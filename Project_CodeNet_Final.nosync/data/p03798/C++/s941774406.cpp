#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string word;
bool type[100005];

int main() {
	cin >> N;
	cin >> word;
	bool one[4] = { true, true, false, false };
	bool two[4] = { true, false, true, false };
	for (int i = 0; i < 4; ++i) {
		type[0] = one[i];
		type[1] = two[i];
		for (int j = 2; j < N; ++j) {
			type[j] = type[j - 1] ^ (word[j - 1] == 'o') ^ type[j - 2];
		}

		if (type[N - 1] ^ (word[N - 1] != 'o')) {
			if (type[N - 2] != type[0])
				continue;
		} else {
			if (type[N - 2] == type[0])
				continue;
		}
		if (type[0] ^ (word[0] != 'o')) {
			if (type[N - 1] != type[1])
				continue;
		} else {
			if (type[N - 1] == type[1])
				continue;
		}

		for (int j = 0; j < N; ++j) {
			if (type[j])
				cout << 'S';
			else
				cout << 'W';
		}
		return 0;
	}
	cout << -1 << endl;
}