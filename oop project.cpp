//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\registration.cpp", registrationform);
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\main.cpp", mainform);
USEFORM("..\..\Documents\Embarcadero\Studio\Projects\login.cpp", loginform);
USEFORM("quizform.cpp", Form1);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(Tmainform), &mainform);
		Application->CreateForm(__classid(Tloginform), &loginform);
		Application->CreateForm(__classid(Tregistrationform), &registrationform);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
