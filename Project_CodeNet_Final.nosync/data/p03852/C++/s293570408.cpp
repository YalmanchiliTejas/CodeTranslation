#include <iostream>
#include <string>

int main()
{
	using namespace std;
	int h = 0;
	char a;
	char b[5] = { 'a', 'e', 'i', 'o', 'u' };
	cin >> a;
	for (int i = 0; i <= 5;i++) {

		if (b[i] == a) {
			h++;
		}
	}
	if (h != 0) {
		cout << "vowel";
	}
	else {
		cout << "consonant";
	}
}