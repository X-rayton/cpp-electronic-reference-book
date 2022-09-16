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
        TButton *Button1;               //"������"
        TButton *Button2;               //"�����"
        TButton *Button3;               //"������"
        TButton *Button4;               //"�����"
        TMemo *Memo1;                   //�����
        TTreeView *TreeView1;           //����������
        TGroupBox *GroupBox2;
        TMainMenu *MainMenu1;
        TMenuItem *N1;                  //"����"
        TMenuItem *N2;                  //"����" -> �����
        TMenuItem *N3;                  //"������"
        TMenuItem *N4;                  //"������" -> � ���������
        TMenuItem *N5;                  //"������" -> "--------"
        TMenuItem *N6;                  //"������" -> �������
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
        //����������
        unsigned char page;  //������� ��������
        static const unsigned char FIRST_PAGE = 0;
        static const unsigned char LAST_PAGE = 17;
        //�������
        void scrollPage(bool forward);
        void editPage(AnsiString title, AnsiString textFile);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
