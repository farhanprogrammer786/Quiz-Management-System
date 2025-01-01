//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include <queue>
#include <string>
#include "quizform.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"


TForm1 *Form1;

class Question {
public:
    std::string text;
    std::string ans1;
    std::string ans2;
    std::string ans3;
    std::string ans4;
    int correctAnswer;

    Question() {}

	// Fixed constructor to pass correctAnswer by value
	Question(const std::string& T, const std::string& a1, const std::string& a2,
			 const std::string& a3, const std::string& a4, int CA)
		: text(T), ans1(a1), ans2(a2), ans3(a3), ans4(a4), correctAnswer(CA) {}
};

std::queue<Question> loadQuestions() {
	Question q1("What is the largest planet in our solar system?", "Earth", "Mars", "Jupiter", "Saturn", 3);
	Question q2("What is the chemical symbol for water?", "F2", "O2", "N2", "H2O", 4);
	Question q3("Who wrote Romeo and Juliet?", "Charles Dickens", "William Shakespeare", "Mark Twain", "J.K. Rowling", 2);
	Question q4("What is the capital of Japan?", "Bangkok", "Islamabad", "Tokyo", "Hong Kong", 3);
	Question q5("Which element has the atomic number 1?", "Hydrogen", "Helium", "Neon", "Fluorine", 1);
	Question q6("What is the capital of France?", "Berlin", "Madrid", "Paris", "Rome", 3);
	Question q7("Which element has the chemical symbol 'O'?", "Oxygen", "Gold", "Iron", "Hydrogen", 1);
	Question q8("What is the smallest prime number?", "0", "1", "2", "3", 3);
	Question q9("What is the square root of 64?", "6", "7", "8", "9", 3);
	Question q10("What is the longest river in the world?", "Amazon", "Nile", "Yangtze", "Mississippi", 2);
	Question q11("Which planet is closest to the Sun?", "Venus", "Earth", "Mercury", "Mars", 3);
	Question q12("What is the largest mammal in the world?", "Elephant", "Blue Whale", "Giraffe", "Hippopotamus", 2);
	Question q13("Which country is known as the Land of the Rising Sun?", "China", "Japan", "Thailand", "South Korea", 2);
	Question q14("What is the freezing point of water in Celsius?", "0", "32", "100", "-1", 1);
	Question q15("Who painted the Mona Lisa?", "Vincent van Gogh", "Leonardo da Vinci", "Pablo Picasso", "Claude Monet", 2);

	std::queue<Question> questions;
	questions.push(q1);
	questions.push(q2);
	questions.push(q3);
	questions.push(q4);
	questions.push(q5);
	questions.push(q6);
	questions.push(q7);
	questions.push(q8);
	questions.push(q9);
	questions.push(q10);
	questions.push(q11);
	questions.push(q12);
	questions.push(q13);
	questions.push(q14);
	questions.push(q15);
	return questions;
}


  std::queue<Question> Quest;
Question currentQuestion;
int selectedans;
int point = 0;
int totalQuestions = 5;  // Set the total number of questions


__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Quest = loadQuestions();
	if (!Quest.empty()) {
		currentQuestion = Quest.front();
		Q->Text = currentQuestion.text.c_str();
		ans1->Text = currentQuestion.ans1.c_str();
		ans2->Text = currentQuestion.ans2.c_str();
		ans3->Text = currentQuestion.ans3.c_str();
		ans4->Text = currentQuestion.ans4.c_str();
		Quest.pop();
		scorelable->Text = "0";

	}
}
void __fastcall TForm1::ans1Change(TObject *Sender)
{
		selectedans = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ans2Change(TObject *Sender)
{
		  selectedans = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ans3Change(TObject *Sender)
{
		  selectedans = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ans4Change(TObject *Sender)
{
		selectedans = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::confirmClick(TObject *Sender)
{
		{
	if (selectedans == currentQuestion.correctAnswer) {
		point++;
		scorelable->Text = IntToStr(point);  // Convert point to string
	}

	if (!Quest.empty()) {
		currentQuestion = Quest.front();
		Q->Text = currentQuestion.text.c_str();
		ans1->Text = currentQuestion.ans1.c_str();
		ans2->Text = currentQuestion.ans2.c_str();
		ans3->Text = currentQuestion.ans3.c_str();
		ans4->Text = currentQuestion.ans4.c_str();
		Quest.pop();

		ans1->IsChecked = false;
		ans2->IsChecked = false;
		ans3->IsChecked = false;
		ans4->IsChecked = false;
	} else {
		confirm->Enabled = false;
		confirm->Text = "Quiz End";  // Disable the button and show "Quiz End"
	}
}

}
//---------------------------------------------------------------------------



