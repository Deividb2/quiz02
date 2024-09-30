#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <vector>

using namespace std;

struct Question {
	string question;
	string options[4];
	int correctResponse;
};

class Mgr_Question {
	string m_question;
	string m_options[4];
	int m_optionCorrect, userResponse;
	int score = 0;

public:

	VOID setQuestion(string questionText, string options[4], int optionCorrect) {
		m_question = questionText;
		for (int i = 0; i < 4; i++) {
			m_options[i] = options[i];
		}
		m_optionCorrect = optionCorrect;
	}

	VOID askQuestion() {
		cout << m_question << endl;
		for (int i = 0; i < 4; i++) {
			cout << i + 1 << ". " << m_options[i] << endl;
		}

		cout << "\nQual � a sua resposta? (em n�mero): ";
		cin >> userResponse;
		checkUserResponse(m_optionCorrect, userResponse);
	}

	VOID checkUserResponse(int correctResponse, int userResponse) {
		if (correctResponse == userResponse) {
			system("cls");
			cout << "Resposta Correta!" << endl;
			this->score += 10;
			system("pause");
			system("cls");
		}
		else {
			system("cls");
			cout << "Resposta Errada!" << endl;
			system("pause");
			system("cls");
		}
	}

	int getScore() {
		return score;
	}

};



int main() {

	setlocale(LC_ALL, "");

	vector<Question> questions = {
		{"Qual � a capital do Brasil?", {"Bras�lia", "Rio de Janeiro", "S�o Paulo", "Salvador"}, 1},
		{"Qual � o maior planeta do Sistema Solar?", {"Merc�rio", "V�nus", "J�piter", "Terra"}, 3},
		{"Qual � o s�mbolo qu�mico da �gua?", {"Corona V�rus", "H2O", "Lula", "Bolsonaro"}, 2},
		{"Em que ano o homem pisou na Lua pela primeira vez?", {"1969", "2000", "1982", "1979"}, 1},
		{"Qual desses animais � um mam�fero?", {"Salm�o", "Lagarto", "Pinguim", "Baleia"}, 4},
		{"Qual � o resultado de 5 x 8?", {"20", "45", "35", "40"}, 4},
		{"Quem escreveu o livro 'Dom Casmurro'?", {"Concei��o Evaristo", "Monteiro Lobato", "Machado de Assis", "Lima Barreto"}, 3},
		{"Qual � o pa�s mais populoso do mundo?", {"R�ssia", "China", "EUA", "Brasil"}, 2},
		{"Quantos continentes existem no mundo?", {"4", "7", "6", "8"}, 2},
		{"Qual a cor do c�u?", {"Verde", "Amarelo", "Vermelho", "Azul"}, 4},
};
	
	Mgr_Question q1;

	for (int i = 0; i < questions.size(); i++) {
		q1.setQuestion(questions[i].question, questions[i].options, questions[i].correctResponse);
		q1.askQuestion();
	}

	system("cls");
	cout << "===== FIM DE JOGO =====\n\n";
	cout << "Sua pontua��o foi: " << q1.getScore() << "\n\n";

	return 0;
}