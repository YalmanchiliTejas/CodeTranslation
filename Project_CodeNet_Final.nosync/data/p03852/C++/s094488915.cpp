#include <iostream>
using namespace std;

int main() {
	char vowel[6] = {'a', 'e', 'i', 'o', 'u'};
	char S[2];
	cin >> S;
	int flag = 0;
	for (int i = 0; i < 5; i++) {
		if (S[0] == vowel[i]) flag = 1;
	}
	if (flag == 1) cout << "vowel" << endl;
	else cout << "consonant" << endl;
}