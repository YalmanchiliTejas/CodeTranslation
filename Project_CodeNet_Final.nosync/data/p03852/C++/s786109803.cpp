#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	char c;
	cin >> c;
	int a = 1;
	a *= (c-'a');
	a *= (c-'e');
	a *= (c-'i');
	a *= (c-'o');
	a *= (c-'u');
	cout << ((a==0)?"vowel":"consonant") << endl;
	return 0;
}
