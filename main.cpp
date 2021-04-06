#include "stdio.h"
#include "stdlib.h"
#include "Phonebook.h"
#include <iostream>
#include <locale>
#include <vector>
#include <fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Phonebook note;
	note.add("John", 89195556409);
	note.add("Alex", 89998887766);
	note.add("Connor", 82223337765);
	cout << "\nВывод списка:\n"<< note;
	note.add("Alex", 97775551234);
	note.erase("John");
	cout << "\nВывод списка:\n" << note;
	try {
		cout << note.find("Alex");
	}
	catch (exception &ex) {
		cout << ex.what();
	}
	cout << note.find(89998887766);
	note.save("C:\\laba\\note.txt");
	Phonebook note1;
	try {
		note1.load("C:\\laba\\note.txt");
	}
	catch (exception &ex) {
		cout << ex.what();
	}

	getchar();
	getchar();
	return 0;
}