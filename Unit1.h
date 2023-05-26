//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label1;
	TLabel *currentPlayerSymbolLabel;
	TLabel *winnerLabel;
	TLabel *Label2;
	TLabel *playerXScore;
	TLabel *Label3;
	TLabel *playerOScore;
	TButton *PlayAgain;
	void __fastcall ButtonClick(TObject *Sender);
	void __fastcall PlayAgainClick(TObject *Sender);
private:	// User declarations
	bool TForm1::CheckIsWinner();
	void TForm1::DisableAllButtons();
	void TForm1::ResetAllButtons();
    bool TForm1::CheckIsDraw();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
