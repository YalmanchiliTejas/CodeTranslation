#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

const int N = 1e6 + 10;
int n;
int a[N];
int d[N];

signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	fill_n(d, N, -1);
	for (int i = 0; i < n; ++i) {
		int l = -1, r = N - 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (d[m] >= a[i]) {
				l = m;
			} else {
				r = m;
			}
			assert(0 <= r && r < N);
		}
		d[r] = a[i];
	}
	cout << (int)(find(d, d + N, -1) - d) << endl;
	return 0;
}

