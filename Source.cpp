#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

void Sist(string&,string&,int&,string&);
void Prikl(string&, string&, int&, string&,string&);
void Web(string&, string&, double&, string&);
int  Menu();
string writeWords();
double writeNumbers();

class Programmirovanie {
protected:
	string name;
	string surname;
public:
	Programmirovanie(string n, string s) {
		name = n;
		surname = s;
	}
	virtual void printInf() = 0;

};

class SistemnoeProgr :public Programmirovanie {
private:
	string language;
	int amount_of_hours;


public:
	SistemnoeProgr(string n, string s, int ho, string l) :Programmirovanie(n, s) {

		amount_of_hours = ho;
		language = l;
	}


	void printInf();
};

class PrikladnoeProgr :public Programmirovanie {
private:
	string language;
	int number_of_course;
	string aim;

public:
	PrikladnoeProgr(string n, string s, int num, string l, string ai) :Programmirovanie(n, s) {
		number_of_course = num;
		language = l;
		aim = ai;
	}


	void printInf();
};

class WebProgr :public Programmirovanie {
private:
	string language;
	double rating;


public:
	WebProgr(string n, string s, double rt, string l) :Programmirovanie(n, s) {
		rating = rt;
		language = l;
	}

	void printInf();
};



void SistemnoeProgr::printInf() {
	cout << "Курсы по системному программированию" << endl;
	cout << "Имя : " << name << endl;
	cout << "Фамилия : " << surname << endl;
	cout << "Язык программирования: " << language << endl;
	cout << "Количество часов по курсу: " << amount_of_hours << endl;

}

void PrikladnoeProgr::printInf() {
	cout << "Курсы по прикладному программированию" << endl;
	cout << "Имя : " << name << endl;
	cout << "Фамилия : " << surname << endl;
	cout << "Язык программирования: " << language << endl;
	cout << "Номер курса: " << number_of_course << endl;
	cout << "Задача курса: " << aim << endl;
}

void WebProgr::printInf() {
	cout << "Курсы по web программированию" << endl;
	cout << "Имя : " << name << endl;
	cout << "Фамилия : " << surname << endl;
	cout << "Язык программирования: " << language << endl;
	cout << "Итоговый балл по курсу " << rating << endl;
}

int Menu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {

		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Курсы системного программирования" << endl; }
		else { cout << " Курсы системного программирования" << endl; }

		if (choose_menu == 1) { cout << " -> Курсы прикладного программирования" << endl; }
		else { cout << " Курсы прикладного программирования" << endl; }

		if (choose_menu == 2) { cout << " -> Курсы Web-программирования" << endl; }
		else { cout << " Курсы Web-программирования" << endl; }

		if (choose_menu == 3) { cout << " -> Полная информация" << endl; }
		else { cout << " Полная информация" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}

void Sist(string& Name, string& Surname, int& h, string& Language) {
	
	cout << "	Курсы по системному программированию " << endl;
	cout << "Имя---  ";
	Name = writeWords();
	cout << endl;
	cout << "Фамилия--- ";
	Surname = writeWords();
	cout << endl;
	cout << "Язык программирования--- ";
	Language = writeWords();
	cout << endl;
	cout << "Количество пройденных часов--- ";
	h = writeNumbers();
	cout << endl;

	system("pause");
	system("cls");
}

void Prikl(string& Name, string& Surname, int& num, string& Language,string&Aim) {
	
	cout << "	Курсы по прикладному программированию" << endl;
	cout << "Имя---  ";
	Name = writeWords();
	cout << endl;
	cout << "Фамилия--- ";
	Surname = writeWords();
	cout << endl;
	cout << "Язык программирования---";
	Language = writeWords();
	cout << endl;
	cout << "Задача курса--- ";
	Aim = writeWords();
	cout << endl;
	cout << "Номер курса/группы--- ";
	num = writeNumbers();
	cout << endl;

	system("pause");
	system("cls");
}

void Web(string& Name, string& Surname, double& r, string& Language) {
	
	cout << "	Курсы по Web-программированию" << endl;
	cout << "Имя---   ";
	Name = writeWords();
	cout << endl;
	cout << "Фамилия--- ";
	Surname = writeWords();
	cout << endl;
	cout << "Итоговый средний балл--- ";
	r = writeNumbers();
	cout << endl;
	cout << "Язык программирования--- ";
	Language = writeWords();
	cout << endl;
	
	system("pause");
	system("cls");
}

int main() {
	setlocale(0, "Russian");
	int n = 1;
	Programmirovanie** mas = new Programmirovanie * [n];
	n--;

	while (true) {
		int choose = Menu();
		if (choose == 0) { 
			int h;
			string Name, Surname, Language;
			Sist(Name, Surname, h, Language);
			mas[n] = new SistemnoeProgr(Name, Surname, h, Language);
			mas[n]->printInf();
			n++;
			n++;
			Programmirovanie** masS = new Programmirovanie * [n];
			n--;
			copy(mas, mas + n, masS);
			mas = masS;
			masS = NULL;
			delete[]masS;
			system("pause");
			system("cls");
		}
        else
			if (choose == 1) { 
				int num;
				string Name, Surname, Language,Aim;
				Prikl(Name, Surname, num, Language,Aim);
				mas[n] = new PrikladnoeProgr(Name, Surname, num, Language,Aim);
				mas[n]->printInf();
				n++;
				n++;
				Programmirovanie** masP = new Programmirovanie * [n];
				n--;
				copy(mas, mas + n, masP);
				mas = masP;
				masP = NULL;
				delete[]masP;
				system("pause");
				system("cls");
				
			}
			else
				if (choose == 2) 
				{ 
					double r;
					string Name, Surname, Language;
					Web(Name, Surname, r, Language);
					mas[n] = new WebProgr(Name, Surname, r, Language);
					mas[n]->printInf();
					n++;
					n++;
					Programmirovanie** masW = new Programmirovanie * [n];
					n--;
					copy(mas, mas + n, masW);
					mas = masW;
					masW = NULL;
					delete[]masW;
					system("pause");
					system("cls");

				}
				else
					if (choose==3)
					{
						for (int i = 0; i < n; i++)
						{
							mas[i]->printInf();
							system("pause");
							system("cls");
						}
					}
				else break;
	}
	return 0;
}

string writeWords()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol >= 'а' && sumbol <= 'я') || (sumbol >= 'А' && sumbol <= 'Я') || sumbol == ' ' || sumbol == '+') {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

double writeNumbers() {
	string numbers;
	while (true) {
		double key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9' || key == ',') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stod(numbers);
}