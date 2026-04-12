#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int counter_a = 0;
	int counter_b = 0;

	for (int i = 0; i < 3; ++i) {
		if ('A' == s[i]) {
			counter_a++;
		}
		else if ('B' == s[i]) {
			counter_b++;
		}
	}

	if (counter_a != 0 && counter_b != 0) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}