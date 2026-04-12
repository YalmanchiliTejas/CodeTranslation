#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

string b = "aeiou";

int main()
{
	//fuck
	string s;
	cin >> s;
	for (int i = 0; i < 5; i++)
	{
		if (s[0] == b[i])
		{
			cout << "vowel" << endl;
			return 0;
		}
	}
	cout << "consonant" << endl;
	return 0;
}