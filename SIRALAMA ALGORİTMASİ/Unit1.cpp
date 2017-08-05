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

 //form aktif olduðunda yani program  çalýþýyorken
Edit2->Text="";//ust sýnýr kutusunu bosalt
Edit3->Text="";//alt sýnýr kutusunu bosalt
Edit4->Text="";//kaç tane kutusunu boþalt
ListBox1->Items->Clear();//sýra listesini temizle
ListBox3->Items->Clear();//oluþan sayi listesini temizle
ListBox5->Items->Clear();//sýralanmýþ haldeki sayi listesini temizle


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//girilen aralýkta random sayi uretme butonu
ComboBox1->Enabled=true;//"sýralama turu" kutucugunu aktif yap..bu butona basmadan önce form aktif iken sýralama turu kutucuðu pasiftir çnkü altsýnýr,ust sýnýr ve kaç edet degerleri girimeden sýralama gerçekleþtirilemeyeðinden form ilk aktif olduðunda pasiftir bu bu degerler girildikten sonra uret butonuna týklandýðýnda sýralama turu kutucuðunu aktif yapar
int i,adet,sayi,alt,ust;//gerekli deðiþkenler tanýmlanýyor..

alt=StrToInt(Edit2->Text);//alt sýnýr bilgisi yukleniyor;
ust=StrToInt(Edit3->Text);//ust sýnýr bilgisi yukleniyor.
adet=StrToInt(Edit4->Text);//adet deðiþkeni kaç adet deðer olacaðý bilgisini taþýyor

if(ust>alt)//bu satýr ust sýnýr sayýsýnýn alt sýnýr sayýsýndan buyuk olacaðý koþulnu taþýyor.
{
for(i=0;i<adet;i++)//random sayýlar uretme dongusu kuruluyor
{

Randomize();
ListBox1->Items->Add(i+1);//listedeki elemanlarýn sayisi kadar 1 den baþlayarak teker teker artýyor ve listbox1 e yazýlýyor
sayi=random(ust-alt+1)+alt;//random sayi aralýðý tanýmlanýyor..parantez dýþýndaki deðer alt sýnýrý,parantez içindeki deðerle pparantez dýþýndaki deðerin toplanmýþ halide ust sýnýrý belirliyor
ListBox3->Items->Add(sayi);//uretilen random sayýlar listeye atanýyor..
}
}
else//ust sýnýrýn alt sýnýrdan kucuk olamayacaðý bilgisi kullanýcýya bildiriliyor
ShowMessage("ust sýnýr alt sýnýrdan eþit yada küçük olamaz");


}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
//sýralama turlerinin bulunduðu kutuyu temsil ediyor..
if(RadioGroup1->ItemIndex==-1)//sýralama þeklinde iþaretli radio button yoksa anlamýndadýr
{
ShowMessage("lütfen sýralama þeklini seçiniz");//iþaretli buton yoksa kullanýcýyý uyarýyor ve sýralama þeklinin girilmesini istiyor
}
else//sýralama þeklinde basýlý buton var anlamýndadýr
{
if(RadioGroup1->ItemIndex==1)//eðer sýralama þekli büyükten küçüðe doðruysa bu komutlarý kullan anlamýndadýr;
{
if(ComboBox1->ItemIndex==0)//SIRALAMA TURU OLARAK ""BUBBLE"" sort seçiliyse
{
//bubble sort dongu deðiþkenleri tanýmlanýyor ve sýralama iþlemleri gerçekleþtiriliyor

ListBox5->Items->Clear();//DÝZÝ SIRALAMA ÝÞLEMÝ YAPMADAN ÖNCE LÝSTENÝN TEMÝZLENMESÝNÝ SAÐLAR
labelfalse();//grafik bilgilerinin okunduðu deðerlerin bulunduðu deðerlerin seçilen algoritmaya gore aktif olmasýný gerçekleþtiren komut
bubble->Visible=true;//algoritmanýn saniye deðerinin tutulduðu kutucugun aktif olmasýdýr
basla=GetTickCount();//algoritmanýn ne kadar surede iþlediði sürecinin baþladýðý nokta
DynamicArray<int>dizi;//dizinin tanýmlama bilgisi
int i,j,adet,deger; //degiþken tanýmlamasý
adet=StrToInt(Edit4->Text);//formda ekrana girilen kaç adet degerinin tutulduðu yer
dizi.Length=adet;//dizinin ne kadar boyutta olacaðýný belirtiyor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToFloat(ListBox3->Items->Strings[i]);//random sayýlar diziye aktarýlýyor
for(i=0;i<=adet-1;i++)//BUBBLE SORT algoritmasýnýn baþladýðý nokta
{
for(j=adet-1;j>i;j--)
{
if(dizi[j-1]<dizi[j])//dizi içinde yer deðiþtirme iþlemleri gerçekleþiyor
{
deger=dizi[j];
dizi[j]=dizi[j-1];
dizi[j-1]=deger;
}
}
}
for(i=0;i<=adet-1;i++)//dizi  sýralanmýþ olarak listeye yazýlýyor
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();//algoritmanýn kaç saniyede gerçekleþtiði bilgisini tutan son sure
bubble->Caption=FloatToStr((bitir-basla)/1000);//algoritmanýn gerçek iþlediði saniye deðeri
Series2->Add(StrToFloat(bubble->Caption),"BUBLE SORT B->K",clBlue);//BUBBLE sort algoritmasýnýn grafiye yansýmasý
}
else if(ComboBox1->ItemIndex==1)//SELECTÝON SORT seçiliyse
{
ListBox5->Items->Clear();
labelfalse();
selection->Visible=true;
//selection sort deðiþkenleri tanýmlanýyor ve sýralama iþlemleri gerçekleþtiriliyor
basla=GetTickCount(); //süre baþlangýcý
DynamicArray<int>dizi;//dizi tanýmý
int i,j,adet,deger; //deðiþken ranýmý
adet=StrToInt(Edit4->Text);//dizinin eleman sayýsý
dizi.Length=adet;//dizi boyutlandýrma
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//random sayýlar diziye aktarýlýyor
for(i=0;i<=adet-2;i++)
{
for(j=i+1;j<=adet-1;j++)
{
if(dizi[i]<dizi[j])//dizi içinde yer deðiþtirme iþlemleri gerçekleþiyor
{
deger=dizi[j];
dizi[j]=dizi[i];
dizi[i]=deger;
}
}
}
for(i=0;i<=adet-1;i++) //dizi  listeye yazýlýyor
{
ListBox5->Items->Add(dizi[i]);
}
bitir=GetTickCount();//saniye bitiþi
selection->Caption=FloatToStr((bitir-basla)/1000);//gerçek süre
Series2->Add(StrToFloat(selection->Caption),"SELECTÝON SORT B->K",clRed);//saniyeyi grafikte gosterme
}
else if(ComboBox1->ItemIndex==2)//QUÝCK SORT SEÇÝLÝYSE
{
ListBox5->Items->Clear();//liste temizleme
labelfalse();//süre bilgisi label olaylarý
quick->Visible=true;//label aktif etme

basla=GetTickCount();//süre baþlangýcý
//quick  sort deðiþkenleri tanýmlanýyor ve sýralama iþlemleri gerçekleþtiriliyor
int i,n;//deðiþken tanýmý
adet=StrToInt(Edit4->Text);//adet bilgisi
dizi.Length=adet;//dizi boyutu
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//random sayýlar diziye aktarýlýyor
sirala(0,adet-1); //tanýmlanmýþ olan void sýrala proseduru çaðýrýlýyor...
for(n=adet-1;n>=0;n--) //sýralanmýþ dizi  listeye yazýlýyor
{
Form1->ListBox5->Items->Add(IntToStr(dizi[n]));
}
bitir=GetTickCount();  //süre bitiþi
quick->Caption=FloatToStr((bitir-basla)/1000);//gerçek süre
Series2->Add(StrToFloat(quick->Caption),"QUÝCK SORT B->K",clYellow);//grafiðe aktarma
}
else if(ComboBox1->ItemIndex==3)//SHELL SORT SEÇÝLÝYSE
{
ListBox5->Items->Clear();//liste temizleme
labelfalse();//label olaylarý
shell->Visible=true;//label aktif
basla=GetTickCount();//süre baþlangýcý
//shell  sort deðiþkenleri tanýmlanýyor ve sýralama iþlemleri gerçekleþtiriliyor
DynamicArray<int>dizi;//dizi tanýmý
int i,j,k,adet,deger,orta_eleman;//deðiþken tanýmý

adet=StrToInt(Edit4->Text);//kaç tane sayý olduðu bilgisi
dizi.Length=adet;//dizi boyutlandýrma
orta_eleman=floor(adet/2);//dizinin orta elemanýný bulmak için
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//random sayýlar diziye aktarýlýyor
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
else  //dizi içinde yer deðiþtirme iþlemleri gerçekleþiyor
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
ListBox5->Items->Add(dizi[i]);//dizi  listeye yazýlýyor

}

bitir=GetTickCount(); //süre bitiþ noktasý
shell->Caption=FloatToStr((bitir-basla)/1000);
Series2->Add(StrToFloat(shell->Caption),"SHELL SORT B->K",clNavy);
}
else if(ComboBox1->ItemIndex==4)//sýralama turu olarak ELEVATOR SORT seçiliyse
{
ListBox5->Items->Clear();//liste temizleme
labelfalse();//label olaylarý
elevator->Visible=true; //label aktif etme
basla=GetTickCount();//süre baþlangýcý
DynamicArray<int>dizi;//dizi deðiþkeni
int i,alt,adet,deger; //deðiþkenler tanýmlanýyor
adet=StrToInt(Edit4->Text); //kaç tane bilgisi yukleniyor
dizi.Length=adet; //dizi boyutlandýrýlýyor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToFloat(ListBox3->Items->Strings[i]);//listedeki deðerler diziye aktarýlýyor
alt=0;
do
{
if(dizi[alt+1]>dizi[alt]) //dongu oluþturuluyor ve yer deðiþtirme iþlemleri gerçekleþiyor
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
ListBox5->Items->Strings[i]=dizi[i];// sýralanan degerler listeye yazýlýyor
}

bitir=GetTickCount();//bitis süresi;
elevator->Caption=FloatToStr((bitir-basla)/1000); //gerçek süre
Series2->Add(StrToFloat(elevator->Caption),"ELEVATOR SORT B->K",clTeal);//grafiðe aktarma
 }
else if(ComboBox1->ItemIndex==5)//sýralama turu olarak BUBBLE-2 SORT seçiliyse
 {
 ListBox5->Items->Clear();//liste temizleniyor
 labelfalse(); //label olaylarý(false durumudur)
 bubble2->Visible=true;//label aktif ediliyor
basla=GetTickCount();//süre baþlangýcý
DynamicArray<int>dizi;//dizi deðiþkeni tanýmlamasý
int i,j,adet,deger;//deðiþkenler tanýmlanýyor
bool yon;//deðiþken tanýmlanýyor
adet=StrToInt(Edit4->Text);//kaç tane sayý olduðu bilgisi giriliyor
dizi.Length=adet;//dizi boyutlandýrýlýyor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]); //listedeki deðerler diziye aktarýlýyor
do
{
yon=true;
for(i=0;i<=adet-2;i++)
{
if(dizi[i]<dizi[i+1])//yer deðiþtirme iþlemleri gerçekleþiyor
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
ListBox5->Items->Add(dizi[i]);//sýralanmýþ dizi listeye aktarýlýyor
}
bitir=GetTickCount(); //süre durduruluyor
bubble2->Caption=FloatToStr((bitir-basla)/1000);//gerçek sure
Series2->Add(StrToFloat(bubble2->Caption),"BUBLE SORT2 B->K",clPurple);//grafiðe aktarýlýyor
}
else if(ComboBox1->ItemIndex==6)//sýralama turu olarak ÝNSERTÝON SORT seçiliyse
{
ListBox5->Items->Clear();//listeyi temizle
labelfalse();//label olaylarý
insertion->Visible=true;//label aktif
basla=GetTickCount();//zaman basla
DynamicArray<int>dizi;//dizi tanýmlanýyor
int adet,i;//deðiþkenler tanýmlanýyor
adet=StrToInt(Edit4->Text);//adet bilgisi giriliyor
dizi.Length=adet;//dizi boyutlandýrýlýyor
for(i=0;i<=adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//oluþan sayýlar diziye aktarýlýyor
}
for( int j=2;j<adet;j++)
{
for(int k=0;k<j;k++)
{
        if (dizi[k]<dizi[j])  //yer deðiþtirme iþlemler yapýlýyor
      {
        int temp=dizi[k];
        dizi[k]=dizi[j];
        dizi[j]=temp;
      }
    }
  }
 for (int i = 0; i <= adet-1; i++)
 {
 ListBox5->Items->Strings[i]=dizi[i];//sýralnmýþ dizi listeye aktarýlýyor
 }
 bitir=GetTickCount();//süreyi durdur
insertion->Caption=FloatToStr((bitir-basla)/1000);//gerçek zaman
Series2->Add(StrToFloat(insertion->Caption),"INSERTION SORT B->K",clOlive);//grafiðe aktar
}
else if(ComboBox1->ItemIndex==7)//sýralama turu olarak SHAKER  SORT seçiliyse
{
ListBox5->Items->Clear();//liste temizleniyor
labelfalse();//label olaylarý
shaker->Visible=true;//label aktif ediliyor
basla=GetTickCount();//sure baþlýyor
DynamicArray<int>dizi; //dizi tanýmlanýyor
int i,deger,adet;//degiþkenler tanýmlanýyor
adet=StrToInt(Edit4->Text); //adet bilgisi giriliyor
dizi.Length=adet;//dizi boyutlandýrýlýyor
boolean degisti;//deðiþken tanýmlanýyor

for(i=0;i<=adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//sayýlar diziye aktarýlýyor
}
int MaxYer=adet,MinYer=1;
do
{
degisti=false;
for(int i=MinYer;i<MaxYer;i++)
{
if(dizi[i]>dizi[i-1]) //yer deðiþtirme iþlemleri gerçekleþiyor
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
if(dizi[i-1]<dizi[i])//yer deðiþtirme iþlemleri gerçekleþiyor
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
ListBox5->Items->Strings[i]=dizi[i];// dizi listeye aktarýlýyor
}
bitir=GetTickCount();//sure durduruluyor
shaker->Caption=FloatToStr((bitir-basla)/1000);///geçen zaman hesaplanýyor
Series2->Add(StrToFloat(shaker->Caption),"SHAKER SORT B->K",clBtnFace);//deðerler grafiðe aktarýlýyor
}
else if(ComboBox1->ItemIndex==8)//sýralama turu olarak BINARY INSERTION  SORT seçiliyse
{
ListBox5->Items->Clear();//liste temizleniyor
labelfalse(); //label olaylarý
binary->Visible=true;//label aktid ediliyor
basla=GetTickCount();//zaman baþlatýlýyor
DynamicArray<int>dizi; // dizi tanýmlanýyor
int orta,i,j,deger,adet,alt,ust;//ðiþkenler tanýmlanýyor
adet=StrToInt(Edit4->Text);//adet bilgisi giriliyor
dizi.Length=adet;//dizi boyutlandýrýlýyor
for(i=0;i<=adet-1;i++)
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//sayýlar diziye aktarýlýyor
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
ListBox5->Items->Strings[i]=dizi[i];//dizi deðerleri listaye aktarýlýyor
}
bitir=GetTickCount();//zaman durduruluyor
binary->Caption=FloatToStr((bitir-basla)/1000);//gerçek zaman hesaplanýyor
Series2->Add(StrToFloat(binary->Caption),"BINARY SORT B->K",clBlack);//grafiðe aktarýlýyor
}
else if(ComboBox1->ItemIndex==9)//sýralama turu olarak SHAKER  SORT-2 seçiliyse
{
ListBox5->Items->Clear();//liste temizleniyor
labelfalse();//label olaylarý oluþuyor
shaker2->Visible=true;//label aktif ediliyor
basla=GetTickCount();//süreç baþlýyor
DynamicArray<int>dizi;//dizi tanýmlanýyor
int deger,n,adet,m,i;//deðiþkenler tanýmlanýyor
adet=StrToInt(Edit4->Text);//adet bilgisi giriliyor
dizi.Length=adet; //dizi boyutlndýrýlýyor
for(i=0;i<adet-1;i++)
{
dizi[i]=StrToInt(ListBox3->Items->Strings[i]);//sayýlar diziye aktarýlýyor
}
for(n=adet/2;n>0;n=n/2)
{
for(m=n;m>0;m=m/2)
{
for(i=0;i<adet-m;i++)
{
if(dizi[i]>dizi[i+m])//yer deðiþtirme iþlemleri gerçekleþiyor
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
if(dizi[j+1]>dizi[j])  //yer deðiþtirme iþlemleri gerçekleþiyor
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
shaker2->Caption=FloatToStr((bitir-basla)/1000);//düre bilgisi hesaplanýyor
Series2->Add(StrToFloat(shaker2->Caption),"SHAKER SORT2 B->K",clAqua);//deðerler grafiðe yansýtýlýyor
}
//YENÝ EKLEMELERÝNÝZÝ BU ARALIÐA YAPINIZ..

}//buyukten küçüðe kýsmýnýn bittiði dongu sonu iþaretidir

else//eðer sýralama þekli  küçükten büyüðe doðruysa bu komutlarý kullan anlamýndadýr;

//burdaki fonksiyon içerikleri açýklanmýyacaktýr
//çünkü ustteki fonksiyonlarla ayný bilgiyi taþýmaktadýrlar
//tek farklari küçükten büyüðe doðru sýralanmýþ olmalarýdýr
{
if(ComboBox1->ItemIndex==0)//sýralama turu olarak bubble sort seçiliyse
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
else if(ComboBox1->ItemIndex==1)//sýralama turu olarak selection sort seçiliyse
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
Series2->Add(StrToFloat(selection->Caption),"SELECTÝON SORT K->B",clRed);
}
else if(ComboBox1->ItemIndex==2)//sýralama turu olarak quick sort seçiliyse
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
Series2->Add(StrToFloat(quick->Caption),"QUÝCK SORT K->B",clYellow);
}
else if(ComboBox1->ItemIndex==3)//sýralama turu olarak shell sort seçiliyse
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
else if(ComboBox1->ItemIndex==4)//sýralama turu olarak elevator sort seçiliyse
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
else if(ComboBox1->ItemIndex==5)//sýralama turu olarak bubble-2 sort seçiliyse
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
else if(ComboBox1->ItemIndex==6)//sýralama turu olarak insertion sort seçiliyse
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
else if(ComboBox1->ItemIndex==7)//sýralama turu olarak SHAKER  SORT seçiliyse
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
else if(ComboBox1->ItemIndex==8)//sýralama turu olarak BINARY INSERTION  SORT seçiliyse
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
else if(ComboBox1->ItemIndex==9)//sýralama turu olarak SHAKER  SORT-2 seçiliyse
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
//YENÝ SIRALAMA TURLERÝNÝ BU NOKTADAN ÝTÝBAREN YAZILACAKTIR




}
}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ComboBox2Change(TObject *Sender)
//temizleme iþlemlerinin yapýldýðý butondur..
{
if(ComboBox2->ItemIndex==0)//sadece sýralanmýþ deðerlerin olduðu listeyi temizler
{
ListBox5->Items->Clear();
}
else if(ComboBox2->ItemIndex==1)//grafiði temizle
{
Series2->Clear();
labelfalse();
}

else//formdaki herþeyi sýfýrlar ve yeniden random sayi uretme iþlemine tabi tutar kullanýcýyý
{
ListBox1->Items->Clear();
ListBox3->Items->Clear();
ListBox5->Items->Clear();
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
labelfalse();
RadioGroup1->ItemIndex=-1;
ComboBox1->Enabled=false;//alt sýnýr,ustsýnýr,kaç tane bilgisi temizlendiðinden ötürü sýralama turu butonunu pasif yapar.bunu aktif hale getirecek buton uret butonudur
Series2->Clear();
}
}
//---------------------------------------------------------------------------
      //QUÝCK SORT algoritmasýna ait sýralama iþlemlerini yapan prosedurdur

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

//grafiðe aktarýlacak zaman deðerlerini tutan labellerin pasif olmasýný saðilýyor
//hangi sýralama turu seçilirse o zaten program içerisinde aktif olarak deðeri
//grafiðe yansýtýlacaktýr

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
//PROGRAM ÝÇERÝSÝNDEKÝ algoritma baþlýk altýndaki sýralama algoritmalarýnýn
//gosterildiði memo'nun kordinatlatýnýn neresi olacaðý bilgisini tutuyor
//kullanýcý algoritma baþlýðý altýndaki sýralama turlerinden herhangi birini
//seçtiðinde bilgilerin gosterilebilmesi için memo boyutlandýrýýyor ve kapat düðmesi
//boyutlandýrýlýyor düðmeye basýldýðý anda memo ve button pasif hale geliyor
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
//GRAFÝÐÝN KULLANDIÐI LABELLERÝN HEPSÝNÝN BAÞLANDIÐÇA PASÝF OLMASI
//SAÐLANIYOR SEÇÝM YAPILDIKTA O SEÇÝME AÝT LABELLER AKTÝF OLACAKTIR

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

