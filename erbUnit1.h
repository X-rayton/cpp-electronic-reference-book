//---------------------------------------------------------------------------

#ifndef erbUnit1H
#define erbUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TButton *Button1;               //"начало"
        TButton *Button2;               //"назад"
        TButton *Button3;               //"вперед"
        TButton *Button4;               //"конец"
        TMemo *Memo1;                   //текст
        TTreeView *TreeView1;           //оглавление
        TGroupBox *GroupBox2;
        TMainMenu *MainMenu1;
        TMenuItem *N1;                  //"Файл"
        TMenuItem *N2;                  //"Файл" -> Выход
        TMenuItem *N3;                  //"Помощь"
        TMenuItem *N4;                  //"Помощь" -> О программе
        TMenuItem *N5;                  //"Помощь" -> "--------"
        TMenuItem *N6;                  //"Помощь" -> Справка
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall TreeView1Change(TObject *Sender, TTreeNode *Node);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        //переменные
        unsigned char page;  //счетчик страницы
        static const unsigned char FIRST_PAGE = 0;
        static const unsigned char LAST_PAGE = 17;
        //функции
        void scrollPage(bool forward);
        void editPage(AnsiString title, AnsiString textFile);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
