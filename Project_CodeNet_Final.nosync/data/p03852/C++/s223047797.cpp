#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	char a;
	cin >> a;
	if (a == 'a' || a == 'e' ||a == 'i' ||a == 'o' ||a == 'u') {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}
	
	return 0;
}