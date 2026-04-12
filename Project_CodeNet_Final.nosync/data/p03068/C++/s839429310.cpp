#include <iostream>
using namespace std;

int main() {
	int n, k;
	char s[20];
	cin >> n;
	cin >> s;
	cin >> k;

	for (int i = 0; i < n; i++) {
		if (s[i] == s[k - 1]) cout << s[i];
		else cout << "*";
	}

	return 0;
}