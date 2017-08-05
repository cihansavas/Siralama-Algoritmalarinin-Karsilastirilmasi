//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include<math.h>
#include<iostream.h>
#include<conio.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormActivate(TObject *Sender)
{

 //form aktif oldu�unda yani program  �al���yorken
Edit2->Text="";//ust s�n�r kutusunu bosalt
Edit3->Text="";//alt s�n�r kutusunu bosalt
Edit4->Text="";//ka� tane kutusunu bo�alt
ListBox1->Items->Clear();//s�ra listesini temizle
ListBox3->Items->Clear();//olu�an sayi listesini temizle
ListBox5->Items->Clear();//s�ralanm�� haldeki sayi listesini temizle


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//girilen aral�kta random sayi uretme butonu
ComboBox1->Enabled=true;//"s�ralama turu" kutucugunu aktif yap..bu butona basmadan �nce form aktif iken s�ralama turu kutucu�u pasiftir �nk� alts�n�r,ust s�n�r ve ka� edet degerleri girimeden s�ralama ger�ekle�tirilemeye�inden form ilk aktif oldu�unda pasiftir bu bu degerler girildikten sonra uret butonuna t�kland���nda s�ralama turu kutucu�unu aktif yapar
int i,adet,sayi,alt,ust;//gerekli de�i�kenler tan�mlan�yor..

alt=StrToInt(Edit2->Text);//alt s�n�r bilgisi yukleniyor;
ust=StrToInt(Edit3->Text);//ust s�n�r bilgisi yukleniyor.
adet=StrToInt(Edit4->Text);//adet de�i�keni ka� adet de�er olaca�� bilgisini ta��yor

if(ust>alt)//bu sat�r ust s�n�r say�s�n�n alt s�n�r say�s�ndan buyuk olaca�� ko�ulnu ta��yor.
{
for(i=0;i<adet;i++)//random say�lar uretme dongusu kuruluyor
{

Randomize();
ListBox1->Items->Add(i+1);//listedeki elemanlar�n sayisi kadar 1 den ba�layarak teker teker art�yor ve listbox1 e yaz�l�yor
sayi=random(ust-alt+1)+alt;//random sayi aral��� tan�mlan�yor..parantez d���ndaki de�er alt s�n�r�,parantez i�indeki de�erle pparantez d���ndaki de�erin toplanm�� halide ust s�n�r� belirliyor
ListBox3->Items->Add(sayi);//uretilen random say�lar listeye atan�yor..
}
}
else//ust s�n�r�n alt s�n�rdan kucuk olamayaca�� bilgisi kullan�c�ya bildiriliyor
ShowMessage("ust s�n�r alt s�n�rdan e�it yada k���k olamaz");


}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
//s�ralama turlerinin bulundu�u kutuyu temsil ediyor..
if(RadioGroup1->ItemIndex==-1)//s�ralama �eklinde i�aretli radio button yoksa anlam�ndad�r
{
ShowMessage("l�tfen s�ralama �eklini se�iniz");//i�aretli buton yoksa kullan�c�y� uyar�yor ve s�ralama �eklinin girilmesini istiyor
}
else//s�ralama �eklinde bas�l� buton var anlam�ndad�r
{
if(RadioGroup1->ItemIndex==1)//e�er s�ralama �ekli b�y�kten k����e do�ruysa bu komutlar� kullan anlam�ndad�r;
{
if(ComboBox1->ItemIndex==0)//SIRALAMA TURU OLARAK ""BUBBLE"" sort se�iliyse
{
//bubble sort dongu de�i�kenleri tan�mlan�yor ve s�ralama i�lemleri ger�ekle�tiriliyor

ListBox5->Items->Clear();//D�Z� SIRALAMA ��LEM� YAPMADAN �NCE L�STEN�N TEM�ZLENMES�N� SA�LAR
labelfalse();//grafik bilgilerinin okundu�u de�erlerin bulundu�u de�erlerin se�ilen algoritmaya gore aktif olmas�n� ger�ekle�tiren komut
bubble->Visible=true;//algoritman�n saniye de�erinin tutuldu�u kutucugun aktif olmas�d�r
basla=GetTickCount();//algoritman�n ne kadar surede i�ledi�i s�recinin ba�lad��� nokta
DynamicArray<int>dizi;//dizinin tan�mlama bilgisi
int i,j,adet,deger; //degi�ken tan�mlamas�
adet=StrToInt(Edit4->Text);//formda ekrana girilen ka� adet degerinin tutuldu�u yer
dizi.Length=adet;//dizinin ne kadar boyutta olaca��n� belirtiyor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToFloat(ListBox3->Items->Strings[i]);//random say�lar diziye aktar�l�yor
for(i=0;i<=adet-1;i++)//BUBBLE SORT algoritmas�n�n ba�lad��� nokta
{
for(j=adet-1;j>i;j--)
{
if(dizi[j-1]<dizi[j])//dizi i�inde yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[j];
dizi[j]=dizi[j-1];
dizi[j-1]=deger;
}
}
}
for(i=0;i<=adet-1;i++)//dizi  s�ralanm�� olarak listeye yaz�l�yor
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();//algoritman�n ka� saniyede ger�ekle�ti�i bilgisini tutan son sure
bubble->Caption=FloatToStr((bitir-basla)/1000);//algoritman�n ger�ek i�ledi�i saniye de�eri
Series2->Add(StrToFloat(bubble->Caption),"BUBLE SORT B->K",clBlue);//BUBBLE sort algoritmas�n�n grafiye yans�mas�
}
else if(ComboBox1->ItemIndex==1)//SELECT�ON SORT se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
selection->Visible=true;
//selection sort de�i�kenleri tan�mlan�yor ve s�ralama i�lemleri ger�ekle�tiriliyor
basla=GetTickCount(); //s�re ba�lang�c�
DynamicArray<int>dizi;//dizi tan�m�
int i,j,adet,deger; //de�i�ken ran�m�
adet=StrToInt(Edit4->Text);//dizinin eleman say�s�
dizi.Length=adet;//dizi boyutland�rma
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//random say�lar diziye aktar�l�yor
for(i=0;i<=adet-2;i++)
{
for(j=i+1;j<=adet-1;j++)
{
if(dizi[i]<dizi[j])//dizi i�inde yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[j];
dizi[j]=dizi[i];
dizi[i]=deger;
}
}
}
for(i=0;i<=adet-1;i++) //dizi  listeye yaz�l�yor
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();//saniye biti�i
selection->Caption=FloatToStr((bitir-basla)/1000);//ger�ek s�re
Series2->Add(StrToFloat(selection->Caption),"SELECT�ON SORT B->K",clRed);//saniyeyi grafikte gosterme
}
else if(ComboBox1->ItemIndex==2)//QU�CK SORT SE��L�YSE
{
ListBox5->Items->Clear();//liste temizleme
labelfalse();//s�re bilgisi label olaylar�
quick->Visible=true;//label aktif etme

basla=GetTickCount();//s�re ba�lang�c�
//quick  sort de�i�kenleri tan�mlan�yor ve s�ralama i�lemleri ger�ekle�tiriliyor
int i,n;//de�i�ken tan�m�
adet=StrToInt(Edit4->Text);//adet bilgisi
dizi.Length=adet;//dizi boyutu
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//random say�lar diziye aktar�l�yor
sirala(0,adet-1); //tan�mlanm�� olan void s�rala proseduru �a��r�l�yor...
for(n=adet-1;n>=0;n--) //s�ralanm�� dizi  listeye yaz�l�yor
{
Form1->ListBox5->Items->Add(IntToStr(dizi[n]));
}
bitir=GetTickCount();  //s�re biti�i
quick->Caption=FloatToStr((bitir-basla)/1000);//ger�ek s�re
Series2->Add(StrToFloat(quick->Caption),"QU�CK SORT B->K",clYellow);//grafi�e aktarma
}
else if(ComboBox1->ItemIndex==3)//SHELL SORT SE��L�YSE
{
ListBox5->Items->Clear();//liste temizleme
labelfalse();//label olaylar�
shell->Visible=true;//label aktif
basla=GetTickCount();//s�re ba�lang�c�
//shell  sort de�i�kenleri tan�mlan�yor ve s�ralama i�lemleri ger�ekle�tiriliyor
DynamicArray<int>dizi;//dizi tan�m�
int i,j,k,adet,deger,orta_eleman;//de�i�ken tan�m�

adet=StrToInt(Edit4->Text);//ka� tane say� oldu�u bilgisi
dizi.Length=adet;//dizi boyutland�rma
orta_eleman=floor(adet/2);//dizinin orta eleman�n� bulmak i�in
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//random say�lar diziye aktar�l�yor
while(orta_eleman>0)
{
for(i=orta_eleman;i<=adet-1;i++)
{
j=i-orta_eleman;
while(j>=0)
{
k=j+orta_eleman;
if(dizi[k]<=dizi[j])
{
j=-1;
}
else  //dizi i�inde yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[j];
dizi[j]=dizi[k];
dizi[k]=deger;
j=j-orta_eleman;
}
}
}
orta_eleman=floor(orta_eleman/2);//dizideki orta eleman bulunuyor
}
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Add(dizi[i]);//dizi  listeye yaz�l�yor

}

bitir=GetTickCount(); //s�re biti� noktas�
shell->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(shell->Caption),"SHELL SORT B->K",clNavy);
}
else if(ComboBox1->ItemIndex==4)//s�ralama turu olarak ELEVATOR SORT se�iliyse
{
ListBox5->Items->Clear();//liste temizleme
labelfalse();//label olaylar�
elevator->Visible=true; //label aktif etme
basla=GetTickCount();//s�re ba�lang�c�
DynamicArray<int>dizi;//dizi de�i�keni
int i,alt,adet,deger; //de�i�kenler tan�mlan�yor
adet=StrToInt(Edit4->Text); //ka� tane bilgisi yukleniyor
dizi.Length=adet; //dizi boyutland�r�l�yor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToFloat(ListBox3->Items->Strings[i]);//listedeki de�erler diziye aktar�l�yor
alt=0;
do
{
if(dizi[alt+1]>dizi[alt]) //dongu olu�turuluyor ve yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[alt];
dizi[alt]=dizi[alt+1];
dizi[alt+1]=deger;
if(alt>0)
alt=alt-1;
}
else ++alt;
}
while(alt<adet-1);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];// s�ralanan degerler listeye yaz�l�yor
}

bitir=GetTickCount();//bitis s�resi;
elevator->Caption=FloatToStr((bitir-basla)/1000); //ger�ek s�re
Series2->Add(StrToFloat(elevator->Caption),"ELEVATOR SORT B->K",clTeal);//grafi�e aktarma
 }
else if(ComboBox1->ItemIndex==5)//s�ralama turu olarak BUBBLE-2 SORT se�iliyse
 {
 ListBox5->Items->Clear();//liste temizleniyor
 labelfalse(); //label olaylar�(false durumudur)
 bubble2->Visible=true;//label aktif ediliyor
basla=GetTickCount();//s�re ba�lang�c�
DynamicArray<int>dizi;//dizi de�i�keni tan�mlamas�
int i,j,adet,deger;//de�i�kenler tan�mlan�yor
bool yon;//de�i�ken tan�mlan�yor
adet=StrToInt(Edit4->Text);//ka� tane say� oldu�u bilgisi giriliyor
dizi.Length=adet;//dizi boyutland�r�l�yor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]); //listedeki de�erler diziye aktar�l�yor
do
{
yon=true;
for(i=0;i<=adet-2;i++)
{
if(dizi[i]<dizi[i+1])//yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[i];
dizi[i]=dizi[i+1];
dizi[i+1]=deger;
yon=false;
}
}
}
while(yon==false);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Add(dizi[i]);//s�ralanm�� dizi listeye aktar�l�yor
}
bitir=GetTickCount(); //s�re durduruluyor
bubble2->Caption=FloatToStr((bitir-basla)/1000);//ger�ek sure
Series2->Add(StrToFloat(bubble2->Caption),"BUBLE SORT2 B->K",clPurple);//grafi�e aktar�l�yor
}
else if(ComboBox1->ItemIndex==6)//s�ralama turu olarak �NSERT�ON SORT se�iliyse
{
ListBox5->Items->Clear();//listeyi temizle
labelfalse();//label olaylar�
insertion->Visible=true;//label aktif
basla=GetTickCount();//zaman basla
DynamicArray<int>dizi;//dizi tan�mlan�yor
int adet,i;//de�i�kenler tan�mlan�yor
adet=StrToInt(Edit4->Text);//adet bilgisi giriliyor
dizi.Length=adet;//dizi boyutland�r�l�yor
for(i=0;i<=adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//olu�an say�lar diziye aktar�l�yor
}
for( int j=2;j<adet;j++)
{
for(int k=0;k<j;k++)
{
        if (dizi[k]<dizi[j])  //yer de�i�tirme i�lemler yap�l�yor
      {
        int temp=dizi[k];
        dizi[k]=dizi[j];
        dizi[j]=temp;
      }
    }
  }
 for (int i = 0; i <= adet-1; i++)
 {
 ListBox5->Items->Strings[i]=dizi[i];//s�ralnm�� dizi listeye aktar�l�yor
 }
 bitir=GetTickCount();//s�reyi durdur
insertion->Caption=FloatToStr((bitir-basla)/1000);//ger�ek zaman
Series2->Add(StrToFloat(insertion->Caption),"INSERTION SORT B->K",clOlive);//grafi�e aktar
}
else if(ComboBox1->ItemIndex==7)//s�ralama turu olarak SHAKER  SORT se�iliyse
{
ListBox5->Items->Clear();//liste temizleniyor
labelfalse();//label olaylar�
shaker->Visible=true;//label aktif ediliyor
basla=GetTickCount();//sure ba�l�yor
DynamicArray<int>dizi; //dizi tan�mlan�yor
int i,deger,adet;//degi�kenler tan�mlan�yor
adet=StrToInt(Edit4->Text); //adet bilgisi giriliyor
dizi.Length=adet;//dizi boyutland�r�l�yor
boolean degisti;//de�i�ken tan�mlan�yor

for(i=0;i<=adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//say�lar diziye aktar�l�yor
}
int MaxYer=adet,MinYer=1;
do
{
degisti=false;
for(int i=MinYer;i<MaxYer;i++)
{
if(dizi[i]>dizi[i-1]) //yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[i];
dizi[i]=dizi[i-1];
dizi[i-1]=deger;
degisti=true;
}
}
MaxYer--;
if(!degisti)break;

for(int i=MaxYer-1;i>=MinYer;i--)
{
if(dizi[i-1]<dizi[i])//yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[i];
dizi[i]=dizi[i-1];
dizi[i-1]=deger;
degisti=true;
}
}
MinYer++;
}while(degisti);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];// dizi listeye aktar�l�yor
}
bitir=GetTickCount();//sure durduruluyor
shaker->Caption=FloatToStr((bitir-basla)/1000);///ge�en zaman hesaplan�yor
Series2->Add(StrToFloat(shaker->Caption),"SHAKER SORT B->K",clBtnFace);//de�erler grafi�e aktar�l�yor
}
else if(ComboBox1->ItemIndex==8)//s�ralama turu olarak BINARY INSERTION  SORT se�iliyse
{
ListBox5->Items->Clear();//liste temizleniyor
labelfalse(); //label olaylar�
binary->Visible=true;//label aktid ediliyor
basla=GetTickCount();//zaman ba�lat�l�yor
DynamicArray<int>dizi; // dizi tan�mlan�yor
int orta,i,j,deger,adet,alt,ust;//�i�kenler tan�mlan�yor
adet=StrToInt(Edit4->Text);//adet bilgisi giriliyor
dizi.Length=adet;//dizi boyutland�r�l�yor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//say�lar diziye aktar�l�yor
for(i=1;i<adet;i++)
{
deger=dizi[i];
alt=0;
ust=i-1;
while(alt<=ust)
{
orta=(alt+ust)/2;
if(deger>dizi[orta])
ust=orta-1;
else
alt=orta+1;
}
for(j=i-1;j>=alt;j=j-1)
{
dizi[j+1]=dizi[j];
}
dizi[alt]=deger;
}
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];//dizi de�erleri listaye aktar�l�yor
}
bitir=GetTickCount();//zaman durduruluyor
binary->Caption=FloatToStr((bitir-basla)/1000);//ger�ek zaman hesaplan�yor
Series2->Add(StrToFloat(binary->Caption),"BINARY SORT B->K",clBlack);//grafi�e aktar�l�yor
}
else if(ComboBox1->ItemIndex==9)//s�ralama turu olarak SHAKER  SORT-2 se�iliyse
{
ListBox5->Items->Clear();//liste temizleniyor
labelfalse();//label olaylar� olu�uyor
shaker2->Visible=true;//label aktif ediliyor
basla=GetTickCount();//s�re� ba�l�yor
DynamicArray<int>dizi;//dizi tan�mlan�yor
int deger,n,adet,m,i;//de�i�kenler tan�mlan�yor
adet=StrToInt(Edit4->Text);//adet bilgisi giriliyor
dizi.Length=adet; //dizi boyutlnd�r�l�yor
for(i=0;i<adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//say�lar diziye aktar�l�yor
}
for(n=adet/2;n>0;n=n/2)
{
for(m=n;m>0;m=m/2)
{
for(i=0;i<adet-m;i++)
{
if(dizi[i]>dizi[i+m])//yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[i];
dizi[i]=dizi[i+m];
dizi[i+m]=deger;
}
}
}
}
boolean degisti;
do
{
degisti=false;
for(int j=0;j<adet-1;j++)
if(dizi[j+1]>dizi[j])  //yer de�i�tirme i�lemleri ger�ekle�iyor
{
deger=dizi[j];
dizi[j]=dizi[j+1];
dizi[j+1]=deger;
degisti=true;
}
}while(degisti);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];
}
bitir=GetTickCount();//zaman durduruluyor
shaker2->Caption=FloatToStr((bitir-basla)/1000);//d�re bilgisi hesaplan�yor
Series2->Add(StrToFloat(shaker2->Caption),"SHAKER SORT2 B->K",clAqua);//de�erler grafi�e yans�t�l�yor
}
//YEN� EKLEMELER�N�Z� BU ARALI�A YAPINIZ..

}//buyukten k����e k�sm�n�n bitti�i dongu sonu i�aretidir

else//e�er s�ralama �ekli  k���kten b�y��e do�ruysa bu komutlar� kullan anlam�ndad�r;

//burdaki fonksiyon i�erikleri a��klanm�yacakt�r
//��nk� ustteki fonksiyonlarla ayn� bilgiyi ta��maktad�rlar
//tek farklari k���kten b�y��e do�ru s�ralanm�� olmalar�d�r
{
if(ComboBox1->ItemIndex==0)//s�ralama turu olarak bubble sort se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
bubble->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int i,j,adet,deger;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
dizi[i]=StrToFloat(ListBox3->Items->Strings[i]);
for(i=0;i<=adet-1;i++)
{
for(j=adet-1;j>i;j--)
{
if(dizi[j]<dizi[j-1])
{
deger=dizi[j];
dizi[j]=dizi[j-1];
dizi[j-1]=deger;
}
}
}
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();
bubble->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(bubble->Caption),"BUBLE SORT K->B",clBlue);
}
else if(ComboBox1->ItemIndex==1)//s�ralama turu olarak selection sort se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
selection->Visible=true;

basla=GetTickCount();
DynamicArray<int>dizi;
int i,j,adet,deger;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
for(i=0;i<=adet-2;i++)
{
for(j=i+1;j<=adet-1;j++)
{
if(dizi[j]<dizi[i])
{
deger=dizi[j];
dizi[j]=dizi[i];
dizi[i]=deger;
}
}
}
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();
selection->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(selection->Caption),"SELECT�ON SORT K->B",clRed);
}
else if(ComboBox1->ItemIndex==2)//s�ralama turu olarak quick sort se�iliyse
{
labelfalse();
quick->Visible=true;
basla=GetTickCount();
int i,n;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
sirala(0,adet-1);
for(n=0;n<=adet-1;n++)
{
Form1->ListBox5->Items->Add(IntToStr(dizi[n]));
}
bitir=GetTickCount();
quick->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(quick->Caption),"QU�CK SORT K->B",clYellow);
}
else if(ComboBox1->ItemIndex==3)//s�ralama turu olarak shell sort se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
shell->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int i,j,k,adet,deger,orta_eleman;

adet=StrToInt(Edit4->Text);
dizi.Length=adet;
orta_eleman=floor(adet/2);
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
while(orta_eleman>0)
{
for(i=orta_eleman;i<=adet-1;i++)
{
j=i-orta_eleman;
while(j>=0)
{
k=j+orta_eleman;
if(dizi[j]<=dizi[k])
{
j=-1;
}
else
{
deger=dizi[j];
dizi[j]=dizi[k];
dizi[k]=deger;
j=j-orta_eleman;
}
}
}
orta_eleman=floor(orta_eleman/2);
}
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();
shell->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(shell->Caption),"SHELL SORT K->B",clNavy);
}
else if(ComboBox1->ItemIndex==4)//s�ralama turu olarak elevator sort se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
elevator->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int i,alt,adet,deger;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
dizi[i]=StrToFloat(ListBox3->Items->Strings[i]);
alt=0;
do
{
if(dizi[alt]>dizi[alt+1])
{
deger=dizi[alt];
dizi[alt]=dizi[alt+1];
dizi[alt+1]=deger;
if(alt>0)
alt=alt-1;
}
else ++alt;
}
while(alt<adet-1);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];
}
bitir=GetTickCount();
elevator->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(elevator->Caption),"ELEVATOR SORTK->B",clTeal);
}
else if(ComboBox1->ItemIndex==5)//s�ralama turu olarak bubble-2 sort se�iliyse
 {
 ListBox5->Items->Clear();
 labelfalse();
 bubble2->Visible=true;
 basla=GetTickCount();
DynamicArray<int>dizi;
int i,j,adet,deger;
bool yon;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
do
{
yon=true;
for(i=0;i<=adet-2;i++)
{
if(dizi[i+1]<dizi[i])
{
deger=dizi[i];
dizi[i]=dizi[i+1];
dizi[i+1]=deger;
yon=false;
}
}
}
while(yon==false);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();
bubble2->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(bubble2->Caption),"BUBBLE SORT2 K->B",clPurple);
}
else if(ComboBox1->ItemIndex==6)//s�ralama turu olarak insertion sort se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
insertion->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int adet,i;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
}
for( int j=2;j<adet;j++)
{
for(int k=0;k<j;k++)
{
     if (dizi[j]<dizi[k])
      {
        int temp=dizi[k];
        dizi[k]=dizi[j];
        dizi[j]=temp;
      }
    }
  }
 for (int i = 0; i <= adet-1; i++)
 {
 ListBox5->Items->Strings[i]=dizi[i];
 }

bitir=GetTickCount();
insertion->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(insertion->Caption),"INSERTION SORTK->B",clOlive);
}
else if(ComboBox1->ItemIndex==7)//s�ralama turu olarak SHAKER  SORT se�iliyse
{
 ListBox5->Items->Clear();
 labelfalse();
 shaker->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int i,deger,adet;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
boolean degisti;
for(i=0;i<=adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
}
int MaxYer=adet,MinYer=1;
do
{
degisti=false;
for(int i=MinYer;i<MaxYer;i++)
{
if(dizi[i-1]>dizi[i])
{
deger=dizi[i];
dizi[i]=dizi[i-1];
dizi[i-1]=deger;
degisti=true;
}
}
MaxYer--;
if(!degisti)break;
for(int i=MaxYer-1;i>=MinYer;i--)
{
if(dizi[i]<dizi[i-1])
{
deger=dizi[i];
dizi[i]=dizi[i-1];
dizi[i-1]=deger;
degisti=true;
}
}
MinYer++;
}while(degisti);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];
}
bitir=GetTickCount();
shaker->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(shaker->Caption),"SHAKER SORT K->B",clBtnFace);
}
else if(ComboBox1->ItemIndex==8)//s�ralama turu olarak BINARY INSERTION  SORT se�iliyse
{
ListBox5->Items->Clear();
labelfalse();
binary->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int orta,i,j,deger,adet,alt,ust;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
for(i=1;i<adet;i++)
{
deger=dizi[i];
alt=0;
ust=i-1;
while(alt<=ust)
{
orta=(alt+ust)/2;
if(deger<dizi[orta])
ust=orta-1;
else
alt=orta+1;
}
for(j=i-1;j>=alt;j=j-1)
{
dizi[j+1]=dizi[j];
}
dizi[alt]=deger;
}
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];
}

bitir=GetTickCount();
binary->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(binary->Caption),"BINARY SORT K->B",clBlack);
}
else if(ComboBox1->ItemIndex==9)//s�ralama turu olarak SHAKER  SORT-2 se�iliyse
{

labelfalse();
shaker2->Visible=true;
basla=GetTickCount();
DynamicArray<int>dizi;
int deger,n,adet,m,i;
adet=StrToInt(Edit4->Text);
dizi.Length=adet;
for(i=0;i<adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);
}
for(n=adet/2;n>0;n=n/2)
{
for(m=n;m>0;m=m/2)
{
for(i=0;i<adet-m;i++)
{
if(dizi[i]>dizi[i+m])
{
deger=dizi[i];
dizi[i]=dizi[i+m];
dizi[i+m]=deger;
}
}
}
}
boolean degisti;
do
{
degisti=false;
for(int j=0;j<adet-1;j++)
if(dizi[j]>dizi[j+1])
{
deger=dizi[j];
dizi[j]=dizi[j+1];
dizi[j+1]=deger;
degisti=true;
}
}while(degisti);
for(i=0;i<=adet-1;i++)
{
ListBox5->Items->Strings[i]=dizi[i];
}
bitir=GetTickCount();
shaker2->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(shaker2->Caption),"SHAKER  SORT-2 K->B",clAqua);
}
//YEN� SIRALAMA TURLER�N� BU NOKTADAN �T�BAREN YAZILACAKTIR




}
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ComboBox2Change(TObject *Sender)
//temizleme i�lemlerinin yap�ld��� butondur..
{
if(ComboBox2->ItemIndex==0)//sadece s�ralanm�� de�erlerin oldu�u listeyi temizler
{
ListBox5->Items->Clear();
}
else if(ComboBox2->ItemIndex==1)//grafi�i temizle
{
Series2->Clear();
labelfalse();
}

else//formdaki her�eyi s�f�rlar ve yeniden random sayi uretme i�lemine tabi tutar kullan�c�y�
{
ListBox1->Items->Clear();
ListBox3->Items->Clear();
ListBox5->Items->Clear();
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
labelfalse();
RadioGroup1->ItemIndex=-1;
ComboBox1->Enabled=false;//alt s�n�r,usts�n�r,ka� tane bilgisi temizlendi�inden �t�r� s�ralama turu butonunu pasif yapar.bunu aktif hale getirecek buton uret butonudur
Series2->Clear();
}
}
//---------------------------------------------------------------------------
      //QU�CK SORT algoritmas�na ait s�ralama i�lemlerini yapan prosedurdur

DynamicArray<int>dizi;
int adet;
void TForm1::sirala(int alt,int ust)
{
int i,j,x,deger;
i=alt;j=ust;
x=dizi[floor((alt+ust)/2)];
do
{
while(dizi[i]<x)
{
i++;
}
while(x<dizi[j])
{
j--;
}
if(i<=j)
{
deger=dizi[i];
dizi[i]=dizi[j];
dizi[j]=deger;
i++;j--;
}
}
while(i<j);
if(j>alt)
{
sirala(alt,j);
}
if(i<ust)
{
sirala(i,ust);
}
}



//---------------------------------------------------------------------------

//grafi�e aktar�lacak zaman de�erlerini tutan labellerin pasif olmas�n� sa�il�yor
//hangi s�ralama turu se�ilirse o zaten program i�erisinde aktif olarak de�eri
//grafi�e yans�t�lacakt�r

void TForm1::labelfalse()
{
elevator->Visible=false;
shaker->Visible=false;
shaker2->Visible=false;
bubble->Visible=false;
bubble2->Visible=false;
binary->Visible=false;
insertion->Visible=false;
quick->Visible=false;
shell->Visible=false;
selection->Visible=false;
}


//---------------------------------------------------------------------------
//PROGRAM ��ER�S�NDEK� algoritma ba�l�k alt�ndaki s�ralama algoritmalar�n�n
//gosterildi�i memo'nun kordinatlat�n�n neresi olaca�� bilgisini tutuyor
//kullan�c� algoritma ba�l��� alt�ndaki s�ralama turlerinden herhangi birini
//se�ti�inde bilgilerin gosterilebilmesi i�in memo boyutland�r��yor ve kapat d��mesi
//boyutland�r�l�yor d��meye bas�ld��� anda memo ve button pasif hale geliyor
void TForm1::kodbilgi()
{
Button1->Visible=true;
Memo1->Visible=true;

Button1->Width=75;
Button1->Height=25;
Button1->Left=520;
Button1->Top=12;

Memo1->Width=600;
Memo1->Height=400;
Memo1->Left=0;
Memo1->Top=8;

}


//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//GRAF���N KULLANDI�I LABELLER�N HEPS�N�N BA�LANDI��A PAS�F OLMASI
//SA�LANIYOR SE��M YAPILDIKTA O SE��ME A�T LABELLER AKT�F OLACAKTIR

labelfalse();
}
//---------------------------------------------------------------------------


















void __fastcall TForm1::Button1Click(TObject *Sender)
{
Button1->Visible=false;
Memo1->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BubbleSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//bubblesort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SelectionSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//selectionsort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::QuickSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//quicksort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShellSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//shellsort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ElevatorSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//elevatorsort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BubbleSort21Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//bubblesort2.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nsertionSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//insertionsort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShakerSort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//shakersort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BnarySort1Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//binarysort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ShakerSort21Click(TObject *Sender)
{
kodbilgi();
Memo1->Lines->LoadFromFile("algoritmalar//shaker2sort.txt");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::saylardosyadanal1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::grafikrengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

Chart1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::zeminrengi3Click(TObject *Sender)
{
if(ColorDialog1->Execute())

GroupBox1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::temizlerengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

ComboBox2->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sralamatururengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

ComboBox1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sralanansaylarrengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

ListBox5->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::oluturulansaylarrengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

ListBox3->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sayadetirengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

ListBox1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::katanerengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

Edit4->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::stsnrrengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

Edit3->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::altsnrrengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())

Edit2->Color=ColorDialog1->Color;        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::varsaylandegerler1Click(TObject *Sender)
{
Chart1->Color=clInactiveCaption;
GroupBox1->Color=clInactiveCaption;
ComboBox1->Color=clScrollBar;
ComboBox2->Color=clScrollBar;
ListBox1->Color=clScrollBar;
ListBox3->Color=clScrollBar;
ListBox5->Color=clScrollBar;
Edit2->Color=clScrollBar;
Edit3->Color=clScrollBar;
Edit4->Color=clScrollBar;
RadioGroup1->Color=clInactiveCaption;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sralamaeklirengi1Click(TObject *Sender)
{
if(ColorDialog1->Execute())
RadioGroup1->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::sorunlarnziin1Click(TObject *Sender)
{
GroupBox1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
GroupBox1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
GroupBox1->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
ListBox3->ItemIndex=ListBox1->ItemIndex;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox3Click(TObject *Sender)
{
ListBox1->ItemIndex=ListBox3->ItemIndex;
}
//---------------------------------------------------------------------------

