#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	 string b[] = {"a","e","i","o","u"};
	string a,c;
	c = "consonant";
	cin >> a;
	
	for (int i = 0; i < 5; i++)if (b[i] == a)c = "vowel";
	cout <<c<<endl;
} 