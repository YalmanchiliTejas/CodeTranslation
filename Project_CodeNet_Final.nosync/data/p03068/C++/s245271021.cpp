#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int N, K;
	string s;
	cin >> N >> s >> K;

	for (int i = 0; i < N; ++i) {
		if (s[i] != s[K - 1]) { s[i] = '*'; }
	}

	cout << s << endl;

	return 0;
}
