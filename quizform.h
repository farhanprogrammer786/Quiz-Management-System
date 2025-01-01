//---------------------------------------------------------------------------

#ifndef quizformH
#define quizformH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *confirm;
	TLabel *Q;
	TLabel *score;
	TLabel *scorelable;
	TRadioButton *ans1;
	TRadioButton *ans2;
	TRadioButton *ans3;
	TRadioButton *ans4;
	void __fastcall ans1Change(TObject *Sender);
	void __fastcall ans2Change(TObject *Sender);
	void __fastcall ans3Change(TObject *Sender);
	void __fastcall ans4Change(TObject *Sender);
	void __fastcall confirmClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
