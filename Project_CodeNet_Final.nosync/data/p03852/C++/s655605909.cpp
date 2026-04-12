#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

char c;
string ans = "consonant";

void f(char x) {
	if (c == x) {
		ans = "vowel";
	}
}

int main() {
	cin >> c;
	f('a');
	f('i');
	f('u');
	f('e');
	f('o');
	cout << ans << endl;
	return 0;
}

