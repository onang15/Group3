/***************************************************************
 * Name:      GROUP_3_PROJECTMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Decimal to Binary and Decimal to Hexa Converter ()
 * Created:   2024-03-17
 * Copyright: Decimal to Binary and Decimal to Hexa Converter ()
 * License:
 **************************************************************/

#include "GROUP_3_PROJECTMain.h"
#include <wx/msgdlg.h>
#include <sstream>
#include <bitset>
//(*InternalHeaders(GROUP_3_PROJECTFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GROUP_3_PROJECTFrame)
const long GROUP_3_PROJECTFrame::ID_STATICTEXT1 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_STATICTEXT2 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_TEXTCTRL1 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_TEXTCTRL2 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_STATICTEXT3 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_TEXTCTRL3 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_BUTTON1 = wxNewId();
const long GROUP_3_PROJECTFrame::ID_BUTTON2 = wxNewId();
const long GROUP_3_PROJECTFrame::idMenuQuit = wxNewId();
const long GROUP_3_PROJECTFrame::idMenuAbout = wxNewId();
const long GROUP_3_PROJECTFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GROUP_3_PROJECTFrame,wxFrame)
    //(*EventTable(GROUP_3_PROJECTFrame)
    //*)
END_EVENT_TABLE()

GROUP_3_PROJECTFrame::GROUP_3_PROJECTFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GROUP_3_PROJECTFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxDLG_UNIT(parent,wxSize(-1,-1)));
    SetMinSize(wxSize(-1,-1));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("DECIMAL"), wxPoint(40,48), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("BINARY"), wxPoint(40,192), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(128,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(120,184), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("HEXA"), wxPoint(40,256), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(120,248), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    CONVERTBUTTON = new wxButton(this, ID_BUTTON1, _("CONVERT"), wxPoint(144,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    CONVERTBUTTON->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWFRAME));
    CONVERTBUTTON->SetBackgroundColour(wxColour(255,128,192));
    Button1 = new wxButton(this, ID_BUTTON2, _("CLEAR"), wxPoint(152,312), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnTextCtrl1Text1);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnTextCtrl2Text);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnTextCtrl3Text);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnCONVERTBUTTONClick2);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnAbout);
    //*)
}

GROUP_3_PROJECTFrame::~GROUP_3_PROJECTFrame()
{
    //(*Destroy(GROUP_3_PROJECTFrame)
    //*)
}

void GROUP_3_PROJECTFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GROUP_3_PROJECTFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
void GROUP_3_PROJECTFrame::OnTextCtrl2Text(wxCommandEvent& event)
{
}
void GROUP_3_PROJECTFrame::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void GROUP_3_PROJECTFrame::OnTextCtrl1Text1(wxCommandEvent& event)
{
     long decimalValue;
    if (TextCtrl1->GetValue().ToLong(&decimalValue)) {
        wxString hexValue, binaryValue;

        // Convert decimal to hexadecimal
        std::stringstream ss_hex;
        ss_hex << std::hex << decimalValue;
        hexValue = wxString(ss_hex.str());

        // Convert decimal to binary
        std::stringstream ss_bin;
        ss_bin << std::bitset<8>(decimalValue); // Assuming a 32-bit binary representation
        binaryValue = wxString(ss_bin.str());

        // Update the text controls
        TextCtrl2->SetValue(binaryValue);
        TextCtrl3->SetValue(hexValue);
    }
}

void GROUP_3_PROJECTFrame::OnCONVERTBUTTONClick2(wxCommandEvent& event)
{
    OnTextCtrl1Text1(event);
    Connect(ID_BUTTON1, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&GROUP_3_PROJECTFrame::OnCONVERTBUTTONClick2);

}


void GROUP_3_PROJECTFrame::OnButton2Click(wxCommandEvent& event)
{
    TextCtrl1->SetValue("");
    TextCtrl2->SetValue("");
    TextCtrl3->SetValue("");
}
void GROUP_3_PROJECTFrame::OnClose(wxCloseEvent& event)
{
}

