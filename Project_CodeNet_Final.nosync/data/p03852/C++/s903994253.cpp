#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void) {
	char c, a[5] = { 'a','i','u','e','o' }, f = 0;
	cin >> c;
	for (int i = 0; i < 5; i++)
		if (a[i] == c) f = 1;
	cout << (f == 1 ? "vowel" : "consonant") << endl;
	return 0;
}