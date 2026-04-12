#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<string>


using namespace std;

int main(void)
{
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
	{
		cout << "vowel" << endl;
	}
	else
	{
		cout << "consonant" << endl;
	}
	return 0;
}
