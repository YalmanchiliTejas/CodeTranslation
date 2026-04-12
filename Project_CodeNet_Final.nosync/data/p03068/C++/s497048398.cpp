#include<iostream>
using namespace std;

int main() {
	int n, k;
	char s[10];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	cin >> k;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[k-1]) s[i] = '*';
	}
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}