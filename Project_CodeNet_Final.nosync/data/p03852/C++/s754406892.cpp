#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	char c;
	cin >> c;
	if (c == 'a' || c == 'o' || c == 'u' || c == 'e' || c == 'i') cout << "vowel" << endl;
	else cout << "consonant" << endl;
	return 0;
}