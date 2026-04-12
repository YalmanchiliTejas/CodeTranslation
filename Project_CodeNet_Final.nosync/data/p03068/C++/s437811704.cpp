#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	char s[10000];
	int k;

	cin >> n;
	cin >> s;
	cin >> k;

	char t = s[k - 1];

	for (int i = 0; i < n; i++) {
		if (s[i] == t) {
			cout << s[i];
		}
		else {
			cout << '*';
		}
	}

	return 0;

}