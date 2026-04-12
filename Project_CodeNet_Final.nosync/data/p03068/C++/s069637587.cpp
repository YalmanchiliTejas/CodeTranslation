#include <iostream>

int main() {
	using namespace std;

	int n, k;
	string s;
	char tmp;

	cin >> n >> s >>k;

	tmp = s[k - 1];

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != tmp) {
			cout << "*";
		} else {
			cout << s[i];
		}
	}
	cout << endl;
}