/***************************************************************
 * Name:      GROUP_3_PROJECTMain.h
 * Purpose:   Defines Application Frame
 * Author:    Decimal to Binary and Decimal to Hexa Converter ()
 * Created:   2024-03-17
 * Copyright: Decimal to Binary and Decimal to Hexa Converter ()
 * License:
 **************************************************************/

#ifndef GROUP_3_PROJECTMAIN_H
#define GROUP_3_PROJECTMAIN_H

//(*Headers(GROUP_3_PROJECTFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class GROUP_3_PROJECTFrame: public wxFrame
{
    public:

        GROUP_3_PROJECTFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GROUP_3_PROJECTFrame();

    private:

        //(*Handlers(GROUP_3_PROJECTFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnTextCtrl1Text1(wxCommandEvent& event);
        void OnCONVERTBUTTONClick2(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(GROUP_3_PROJECTFrame)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GROUP_3_PROJECTFrame)
        wxButton* Button1;
        wxButton* CONVERTBUTTON;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)


        DECLARE_EVENT_TABLE()
};

#endif // GROUP_3_PROJECTMAIN_H


