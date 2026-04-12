#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

int main(void) {
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
		cout << "vowel";
		return 0;
	}
	cout << "consonant";
	return 0;
}