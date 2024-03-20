/***************************************************************
 * Name:      GROUP_3_PROJECTApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Decimal to Binary and Decimal to Hexa Converter ()
 * Created:   2024-03-17
 * Copyright: Decimal to Binary and Decimal to Hexa Converter ()
 * License:
 **************************************************************/

#include "GROUP_3_PROJECTApp.h"

//(*AppHeaders
#include "GROUP_3_PROJECTMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GROUP_3_PROJECTApp);

bool GROUP_3_PROJECTApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GROUP_3_PROJECTFrame* Frame = new GROUP_3_PROJECTFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
