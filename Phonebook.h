#pragma once

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include <map>
#include <string>
#include <fstream>

using namespace std;

class Phonebook {
private:
	map<string, unsigned long long> book;
public:
	void add(const string &name, unsigned long long phone);
	void erase(const string &name);
	string find(unsigned long long phone);
	unsigned long long find(const string& name);
	void load(const string& filename);
	void save(const string& filename);
	friend ostream& operator<<(ostream& out, Phonebook& o);
};



void Phonebook::add(const string &name, unsigned long long phone) {
	cout << endl << "���������� ����� " << name << " :";
	auto t = book.emplace(name, phone);
	if (!t.second) 
		cout << "����� ��� ��� ����";
	else
		cout << "���������";
	}


void Phonebook::erase(const string &name) {
	cout << endl << "�������� �� ����� " << name << " :";
	if (!book.erase(name))
		cout << "������ ����� ���";
	else
		cout << "�������";
}


string  Phonebook::find(unsigned long long phone) {
	cout << endl << "����� �� ������ " << phone << ":" << endl;
	for (map<string, unsigned long long> ::iterator it = book.begin(); it != book.end(); ++it) {
		if (it->second == phone) {
			cout << "������� ";
			return it->first;
		}
	}
	throw exception("������ ������ ���");
}


unsigned long long Phonebook::find(const string & name)
{
	cout << endl << "����� �� ����� " << name << ":" << endl;
	map<string, unsigned long long> ::iterator  it = book.find(name);
	if (it != book.end()) {
		cout << "������� ";
		return it->second;
	}
	else {
		throw exception("������ ����� ���");
	}
}


void Phonebook::load(const string & filename)
{
	char str[50];
	size_t i = 0;
	unsigned long long l;
	ifstream file(filename);
	while (!file.eof()) {
		file >> str;
		if (!file.eof()) {
			file >> l;
			book.emplace(str, l);
			i++;
		}
	}
	if (!i)
		throw exception("���� ����");
	file.close();
}

inline void Phonebook::save(const string & filename)
{
	ofstream file;
	file.open(filename);
	for (map<string, unsigned long long> :: iterator it = book.begin(); it != book.end(); ++it) {
		file << it->first << " " << it->second << endl;
	}
	file << endl;
	file.close();
}


 ostream& operator<<(ostream& out, Phonebook& o) {
	out << endl;
	for (map<string, unsigned long long> :: iterator it = o.book.begin(); it != o.book.end(); ++it) {
		out << it->first << " " << it->second << endl;
	}
	out << endl;
	return out;
}
