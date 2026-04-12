#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	char c;
	scanf("%c", &c);

	if (c == 'a' || c == 'i' ||
		c == 'u' || c == 'e' ||
		c == 'o')
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;
}