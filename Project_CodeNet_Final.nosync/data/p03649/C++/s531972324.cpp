
// Problem : E - Decrease (Judge ver.)
// Contest : AtCoder Regular Contest 079
// URL : https://atcoder.jp/contests/arc079/tasks/arc079_c
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define cerr if(1)cerr
#define size(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define temptts template <class T, class... Ts>

const int N = 55, mod = 1e9 + 7, inf = 2e9;

int n;
ll ans = 0, a[N];

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (true) {
		ll mx = 0;
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			if (mx < a[i]) {
				mx = a[i];
				pos = i;
			}
		}
		if (mx < n) {
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (i == pos) {
				a[i] %= n;
			} else {
				a[i] += mx / n;
			}
		}
		ans += mx / n;
	}
	cout << ans;
}
