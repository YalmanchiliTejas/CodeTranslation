
// Problem : D - Remainder Reminder
// Contest : AtCoder Regular Contest 091
// URL : https://atcoder.jp/contests/arc091/tasks/arc091_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()

const int N = 1e6 + 1, mod = 1e9 + 7;

int n, k;
ll ans = 0;

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	if (k == 0) {
		return cout << 1ll * n * n, 0;
	}
	for (int i = k; i <= n; i++) {
		int p = (n + 1) / i;
		ans += (i - k) * p + max(0, (n + 1) % i - k);
	}
	cout << ans;
}
