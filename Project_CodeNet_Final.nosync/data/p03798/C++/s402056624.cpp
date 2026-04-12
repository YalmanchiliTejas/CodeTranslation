#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

map<char, int> state;
map<int, char> animal;

int main()
{
	animal[0] = 'S';
	animal[1] = 'W';
	state['S'] = 0;
	state['W'] = 1;
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t = string(n, ' ');
	bool works = false;
	for (int i = 0; i <= 1; ++i) {
		t[0] = animal[i];
		for (int j = 0; j <= 1; ++j) {
			t[1] = animal[j];
			for (int k = 2; k < n; ++k) {
				if (t[k - 1] == 'S' ^ s[k - 1] == 'o') {
					t[k] = animal[state[t[k - 2]] ^ 1];
				} else {
					t[k] = t[k - 2];
				}
			}
			bool works2 = true;
			for (int k = 0; k < n; ++k) {
				if (t[k] == 'S' ^ s[k] == 'o') {
					if (t[(k - 1 + n) % n] == t[(k + 1) % n]) {
						works2 = false;
						break;
					}
				} else {
					if (t[(k - 1 + n) % n] != t[(k + 1) % n]) {
						works2 = false;
						break;
					}
				}
			}
			if (works2) {
				works = true;
				goto A;
			}
		}
	}
A:
	if (works) {
		cout << t << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}

