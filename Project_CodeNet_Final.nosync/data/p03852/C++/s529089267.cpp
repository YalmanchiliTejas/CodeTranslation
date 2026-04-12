#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<complex>
using namespace std;
typedef long long int llint;
int main(){
	char c;
	cin >> c;
	if (c == 'a' ||
		c == 'i' ||
		c == 'u' ||
		c == 'e' ||
		c == 'o'){
		cout << "vowel" << endl;
	}
	else{
		cout << "consonant" << endl;
	}
	return 0;
}
