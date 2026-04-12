#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n;
	char* s = new char[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	cin >> k;
	for (int i = 0; i < n; i++) {
		if (s[k - 1] != s[i]) {
			cout << '*';
		}
		else {
			cout << s[i];
		}
	}
	return 0;

}
