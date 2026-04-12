#include <iostream>
#include <string>
using namespace std;


int main()
{
	char A[5] = { 'a','e', 'o', 'i', 'u' };
	char op;
	int B=0;
	cin >> op;
	for (int i = 0; i < 5; i++) {
		if (op == A[i]) {
			B = 1;
		}
}
	if (B == 1) {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;

	}
	return 0;
}