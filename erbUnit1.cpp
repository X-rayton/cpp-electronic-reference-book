//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "erbUnit1.h"  
#include "erbAbout.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Form1->ClientHeight = 820;
        Form1->ClientWidth = 770;

        //установка "начального" экрана
        page = FIRST_PAGE;
        TreeView1->FullExpand();                       //развернуть оглавление(дерево)
        TreeView1->Items->Item[page]->Selected = true; //выделить "первую страницу"
        Button1->Enabled = false;
        Button2->Enabled = false;    
        editPage("Мобильные устройства", "texts/mobileDevices.txt");
}       
//---------------------------------------------------------------------------
//изменение содержимого окна
void TForm1::editPage(AnsiString title, AnsiString textFile)
{
        GroupBox1->Caption = title;
        Memo1->Lines->LoadFromFile(textFile);
}
//---------------------------------------------------------------------------
//в какую сторону листаем?
void TForm1::scrollPage(bool forward)
{
        //листать вперед или назад?
        page = page + (forward ? 1 : -1);

        //отобразить измененную страницу в оглавлении
        TreeView1->Items->Item[page]->Selected = true;

        //если не "крайняя" старница, то кнопки нужно разблокировать
        if((page > FIRST_PAGE) && (page < LAST_PAGE))
        {
                Button1->Enabled = true;
                Button2->Enabled = true;
                Button3->Enabled = true;
                Button4->Enabled = true;
        }
        //на первой странице нужно заблокировать кнопки, отвечающие за перемещение назад
        else if(page == FIRST_PAGE)
        {
                Button1->Enabled = false;
                Button2->Enabled = false;
                Button3->Enabled = true;
                Button4->Enabled = true;
        }   
        //на последней странице нужно заблокировать кнопки, отвечающие за перемещение вперёд
        else if(page == LAST_PAGE)
        {
                Button1->Enabled = true;
                Button2->Enabled = true;
                Button3->Enabled = false;
                Button4->Enabled = false;
        }

        switch(page)
        {
                case 0:
                {
                        editPage("Мобильные устройства", "texts/mobileDevices.txt");
                        break;
                }  
                case 1:
                {
                        editPage("Мобильные ОС", "texts/mobileOS.txt");
                        break;
                }     
                case 2:
                {
                        editPage("iOS", "texts/iOS.txt");
                        break;
                }
                case 3:
                {
                        editPage("Symbian OS", "texts/SymbianOS.txt");
                        break;
                }
                case 4:
                {
                        editPage("Blackberry OS", "texts/BlackberryOS.txt");
                        break;
                }
                case 5:
                {
                        editPage("Android", "texts/Android.txt");
                        break;
                }
                case 6:
                {
                        editPage("Windows Mobile", "texts/WindowsMobile.txt");
                        break;
                }
                case 7:
                {
                        editPage("Windows Phone", "texts/WindowsPhone.txt");
                        break;
                }   
                case 8:
                {
                        editPage("Palm OS", "texts/PalmOS.txt");
                        break;
                }   
                case 9:
                {
                        editPage("Maemo OS", "texts/MaemoOS.txt");
                        break;
                }    
                case 10:
                {
                        editPage("MeeGo OS", "texts/MeeGoOS.txt");
                        break;
                }   
                case 11:
                {
                        editPage("Tizen OS", "texts/TizenOS.txt");
                        break;
                }
                case 12:
                {
                        editPage("Ubuntu Touch", "texts/UbuntuTouch.txt");
                        break;
                }  
                case 13:
                {
                        editPage("Firefox OS", "texts/FirefoxOS.txt");
                        break;
                }   
                case 14:
                {
                        editPage("Bada OS", "texts/BadaOS.txt");
                        break;
                }
                case 15:
                {
                        editPage("Sailfish OS", "texts/SailfishOS.txt");
                        break;
                }  
                case 16:
                {
                        editPage("Kai OS", "texts/KaiOS.txt");
                        break;
                }
                case 17:
                {
                        editPage("Справка", "texts/help.txt");
                        break;
                }
                default:
                {
                        GroupBox1->Caption = "Ошибка";
                        Memo1->Lines->Add("Необходимый файл не найден");
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        //переключение на первую страницу
        page = FIRST_PAGE + 1;
        scrollPage(false);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        //переключение на предыдущую страницу
        scrollPage(false);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        //переключение на следующую страницу
        scrollPage(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        //переключение на последнюю страницу
        page = LAST_PAGE - 1;
        scrollPage(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TreeView1Change(TObject *Sender, TTreeNode *Node)
{
        //переключение страниц по нажатию по оглавлению
        page = TreeView1->Selected->AbsoluteIndex - 1;
        scrollPage(true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
        //закрыть программу
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
        //открыть окно "О программе"
        Form2->ShowModal();  //второе окно запрещает использовать первое, пока открыто второе
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{       
        //открыть окно "Справка"
        page = LAST_PAGE - 1;
        scrollPage(true);
}
//---------------------------------------------------------------------------

