#include<iostream>
using namespace std;
char s[4];
int main(){
	cin >> s;
	int flagA = 0, flagB = 0;
	for(int i = 0; i < 3; ++i)
		if(s[i] == 'A') flagA = 1;
		else if(s[i] == 'B') flagB = 1;
	if(flagA and flagB)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}