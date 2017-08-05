//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ToolWin.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TListBox *ListBox3;
        TListBox *ListBox5;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TButton *Button2;
        TLabel *kactane;
        TListBox *ListBox1;
        TLabel *Label2;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TRadioGroup *RadioGroup1;
        TComboBox *ComboBox2;
        TComboBox *ComboBox1;
        TColorDialog *ColorDialog1;
        TLabel *bubble;
        TLabel *selection;
        TLabel *quick;
        TLabel *shell;
        TChart *Chart1;
        TCheckBox *CheckBox1;
        TFastLineSeries *Series1;
        TBarSeries *Series2;
        TLabel *label13;
        TLabel *Label14;
        TLabel *Label1;
        TBarSeries *Series3;
        TLabel *elevator;
        TLabel *bubble2;
        TLabel *binary;
        TLabel *shaker;
        TLabel *insertion;
        TLabel *shaker2;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TMainMenu *MainMenu1;
        TMenuItem *x1;
        TMenuItem *kodarivi1;
        TMenuItem *BubbleSort1;
        TMenuItem *SelectionSort1;
        TMenuItem *QuickSort1;
        TMenuItem *ShellSort1;
        TMenuItem *ElevatorSort1;
        TMenuItem *BubbleSort21;
        TMenuItem *nsertionSort1;
        TMenuItem *ShakerSort1;
        TMenuItem *BnarySort1;
        TMenuItem *ShakerSort21;
        TMenuItem *saylardosyadanal1;
        TMemo *Memo1;
        TMenuItem *ayarlar1;
        TMenuItem *zeminrengi3;
        TMenuItem *altsnrrengi1;
        TMenuItem *stsnrrengi1;
        TMenuItem *katanerengi1;
        TMenuItem *sayadetirengi1;
        TMenuItem *oluturulansaylarrengi1;
        TMenuItem *sralanansaylarrengi1;
        TMenuItem *sralamaeklirengi1;
        TMenuItem *sralamatururengi1;
        TMenuItem *temizlerengi1;
        TMenuItem *grafikrengi1;
        TMenuItem *varsaylandegerler1;
        TMenuItem *hakkmzda1;
        TMenuItem *sorunlarnziin1;
        TImage *Image1;
        TImage *Image2;
        TButton *Button1;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BubbleSort1Click(TObject *Sender);
        void __fastcall SelectionSort1Click(TObject *Sender);
        void __fastcall QuickSort1Click(TObject *Sender);
        void __fastcall ShellSort1Click(TObject *Sender);
        void __fastcall ElevatorSort1Click(TObject *Sender);
        void __fastcall BubbleSort21Click(TObject *Sender);
        void __fastcall nsertionSort1Click(TObject *Sender);
        void __fastcall ShakerSort1Click(TObject *Sender);
        void __fastcall BnarySort1Click(TObject *Sender);
        void __fastcall ShakerSort21Click(TObject *Sender);
        void __fastcall saylardosyadanal1Click(TObject *Sender);
        void __fastcall grafikrengi1Click(TObject *Sender);
        void __fastcall zeminrengi3Click(TObject *Sender);
        void __fastcall temizlerengi1Click(TObject *Sender);
        void __fastcall sralamatururengi1Click(TObject *Sender);
        void __fastcall sralanansaylarrengi1Click(TObject *Sender);
        void __fastcall oluturulansaylarrengi1Click(TObject *Sender);
        void __fastcall sayadetirengi1Click(TObject *Sender);
        void __fastcall katanerengi1Click(TObject *Sender);
        void __fastcall stsnrrengi1Click(TObject *Sender);
        void __fastcall altsnrrengi1Click(TObject *Sender);
        void __fastcall varsaylandegerler1Click(TObject *Sender);
        void __fastcall sralamaeklirengi1Click(TObject *Sender);
        void __fastcall sorunlarnziin1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall ListBox3Click(TObject *Sender);
private:	// User declarations
void sirala(int alt,int ust);
void labelfalse();
void kodbilgi();
int adet;
DynamicArray<int>dizi;
Extended basla;
Extended bitir;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
