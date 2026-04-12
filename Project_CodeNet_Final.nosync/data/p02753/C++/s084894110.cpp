#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	string S;
	cin >> S;
	for (int i = 0; i < (int)S.size(); i++) {
		char c = S[i];
	}
	if (S[0] == S[1] && S[1] == S[2]) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	return 0;
}