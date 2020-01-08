// SearchWordinString.cpp : Defines the entry point for the console application.
//Find substring in a string using KMP method

#include "stdafx.h"

using namespace std;

int main()
{
	string word = "abaabacaddadc";
	string pattern = "abacad";
	map<int, int> mapattern;
	map<int, int>::iterator itr;
	getmapattern(pattern, mapattern);
	if (findpattern(word, pattern, mapattern))
		cout << "Pattern is in word";
	else
		cout << "Pattern is not in the word";

	getchar();
    return 0;
}

//Produce KMP pattern in a map 
void getmapattern(string pattern, map<int, int> &mapattern) {
	int i, j = 0;
	int len = pattern.length();
	map<int, int>::iterator itr;
	mapattern.insert({ 0,0 });
	for (i = 1; i < len; i++) {
		if (pattern[i] == pattern[j]) {
			mapattern.insert({ i, j + 1 });
			j++;
		}
		else {
			if (j == 0)
				mapattern.insert({ i,0 });
			else {
				itr = mapattern.find(j - 1);
				if (itr != mapattern.end())
					j = itr->second;
				if (pattern[i] == pattern[j]) {
					mapattern.insert({ i , j + 1 });
					j++;
				}
				mapattern.insert({ i , j });
			}
		}
	}

	//for (auto it = mapattern.begin(); it != mapattern.end(); ++it)
		//cout << it->first << ' ' << it->second<<"  ";

}

//Find pattern in string using KMP approach
bool findpattern(string word, string pattern, map<int, int> mapattern) {
	int i, j = 0;
	map<int, int>::iterator itr;

	for (i = 0; i < word.length(); i++) {
		if (word[i] == pattern[j])
			j++;
		else {
			itr = mapattern.find(j);
			if (itr != mapattern.end()) {
				j = itr->second;
			}
			if (word[i] == pattern[j])
				j++;
			else
				j = 0;
		}
		if (j == pattern.length())
			return true;
	}
	
	return false;
}