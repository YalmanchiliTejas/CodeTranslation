#include <bits/stdc++.h>

#define rep(i, first, to) for(ll i = first; i < to; ++i)

using namespace std;
typedef long long ll;

char a[5] = {'a', 'i', 'u', 'e', 'o'};
void solve() {
	char c;
	cin >> c;
	bool ans = false;
	rep(i, 0, 5) {
		if (c == a[i]) ans = true;
	}
	if (ans) {
		cout << "vowel" << endl;
	} else {
		cout << "consonant" << endl;
	}
}

int main() {
	solve();
	return 0;
}