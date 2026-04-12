#include <bits/stdc++.h>
using namespace std;

string num, t = "";
int k, n;

long long rec (int j, int cnt) {
	if (cnt == k)
		return t <= num;
	long long res = 0LL;
	for (int i = j; i < n; ++i) {
		if (t[i] == '0') {
			for (char c = '1'; c <= '9'; ++c) {
				t[i] = c;
				res += rec(i + 1, cnt + 1);
				t[i] = '0';
			}
		}
	}
	return res;
}

signed main () {
	cin >> num >> k;
	n = num.size();
	t = string(n, '0');
	cout << rec(0, 0) << '\n';
}
