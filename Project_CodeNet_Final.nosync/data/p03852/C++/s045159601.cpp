#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string A;
	cin >> A;
	int N = 1;
	for (int i = 0; i < N; i++)
	{
		if (A.at(i) == 'a' || A.at(i) == 'i' || A.at(i) == 'u' || A.at(i) == 'e' || A.at(i) == 'o')
			cout << "vowel" << endl;
		else
			cout << "consonant" << endl;
	}
}