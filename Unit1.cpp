//---------------------------------------------------------------------------

#include <fmx.h>
#include <string>
#include <System.SysUtils.hpp>
#pragma hdrstop
using namespace std;

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
char currentPlayerSymbol = 'x';
int playerXScoreValue = 0;
int playerOScoreValue = 0;
//---------------------------------------------------------------------------

bool TForm1::CheckIsWinner() {

	if (Button1->Text==Button2->Text && Button1->Text==Button3->Text && !Button1->Text.IsEmpty()) {
		 return true;
	}
	if (Button4->Text==Button5->Text && Button4->Text==Button6->Text && !Button4->Text.IsEmpty()) {
		 return true;
	}
	if (Button7->Text==Button8->Text && Button7->Text==Button9->Text && !Button7->Text.IsEmpty()) {
		 return true;
	}
	if (Button1->Text==Button4->Text && Button1->Text==Button7->Text && !Button1->Text.IsEmpty()) {
		 return true;
	}
	if (Button2->Text==Button5->Text && Button2->Text==Button8->Text && !Button2->Text.IsEmpty()) {
		 return true;
	}
	if (Button3->Text==Button6->Text && Button3->Text==Button9->Text && !Button3->Text.IsEmpty()) {
		 return true;
	}
	if (Button1->Text==Button5->Text && Button1->Text==Button9->Text && !Button1->Text.IsEmpty()) {
		 return true;
	}
	if (Button3->Text==Button5->Text && Button3->Text==Button7->Text && !Button3->Text.IsEmpty()) {
		 return true;
	}
	return false;
}

bool TForm1::CheckIsDraw() {
	if (Button1->Text.IsEmpty()) {
		return false;;
	}
	if (Button2->Text.IsEmpty()) {
		return false;;
	}
	if (Button3->Text.IsEmpty()) {
		return false;;
	}
	if (Button4->Text.IsEmpty()) {
		return false;;
	}
	if (Button5->Text.IsEmpty()) {
		return false;;
	}
	if (Button6->Text.IsEmpty()) {
		return false;;
	}
	if (Button7->Text.IsEmpty()) {
		return false;;
	}
	if (Button8->Text.IsEmpty()) {
		return false;;
	}
	if (Button9->Text.IsEmpty()) {
		return false;;
	}
	return true;
}

void TForm1::DisableAllButtons() {
	Button1->Enabled=False;
	Button2->Enabled=False;
	Button3->Enabled=False;
	Button4->Enabled=False;
	Button5->Enabled=False;
	Button6->Enabled=False;
	Button7->Enabled=False;
	Button8->Enabled=False;
	Button9->Enabled=False;
}

void TForm1::ResetAllButtons() {
	Button1->Enabled=True;
	Button2->Enabled=True;
	Button3->Enabled=True;
	Button4->Enabled=True;
	Button5->Enabled=True;
	Button6->Enabled=True;
	Button7->Enabled=True;
	Button8->Enabled=True;
	Button9->Enabled=True;
	Button1->Text="";
	Button2->Text="";
	Button3->Text="";
	Button4->Text="";
	Button5->Text="";
	Button6->Text="";
	Button7->Text="";
	Button8->Text="";
	Button9->Text="";
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	currentPlayerSymbolLabel->Text=currentPlayerSymbol;
	playerXScore->Text=IntToStr(playerXScoreValue);
	playerOScore->Text=IntToStr(playerOScoreValue);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	TButton* clickedButton=dynamic_cast<TButton*>(Sender);
	clickedButton->Text=currentPlayerSymbol;
	clickedButton->Enabled=False;

	if (CheckIsWinner()) {
		winnerLabel->Text="You won!";
		if (currentPlayerSymbol == 'x') {
			playerXScoreValue++;
			playerXScore->Text=playerXScoreValue;
		} else {
			playerOScoreValue++;
			playerOScore->Text=playerOScoreValue;
        }
		DisableAllButtons();
		PlayAgain->Enabled=True;
		return;    
	}

	if (CheckIsDraw()) {
		winnerLabel->Text="Draw :(";
		PlayAgain->Enabled=True;
		return;	
	}

	if (currentPlayerSymbol == 'x') {
		currentPlayerSymbol = 'o';
	} else {
		currentPlayerSymbol = 'x';
	}

	currentPlayerSymbolLabel->Text=currentPlayerSymbol;
}

void __fastcall TForm1::PlayAgainClick(TObject *Sender)
{
	PlayAgain->Enabled=False;
	winnerLabel->Text="";
	ResetAllButtons();

	if (currentPlayerSymbol == 'x') {
		currentPlayerSymbol = 'o';
	} else {
		currentPlayerSymbol = 'x';
	}
	
	currentPlayerSymbolLabel->Text=currentPlayerSymbol;
}
//---------------------------------------------------------------------------


