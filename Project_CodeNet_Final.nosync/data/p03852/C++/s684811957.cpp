#include <iostream>
using namespace std;

int main(void) {

	char c, boin[6] = "aiueo", co = 0;

	cin >> c;
	
	for (int i = 0; i < 5; i++)
		if (c == boin[i]) co = 1;

	if (co == 1) cout << "vowel" << endl;
	else cout << "consonant" << endl;

	return 0;

}