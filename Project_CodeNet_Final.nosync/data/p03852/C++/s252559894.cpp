#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	char c;
	cin >> c;

	int f = 0;
	if (c == 'a') f = 1;
	if (c == 'e') f = 1;
	if (c == 'i') f = 1;
	if (c == 'o') f = 1;
	if (c == 'u') f = 1;

	if (f) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}
}