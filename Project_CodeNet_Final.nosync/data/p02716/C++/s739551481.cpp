#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 123;
const ll inf = 1e18;
int n, p[3][N];
ll pr[3][N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	int odd = n & 1;
	n /= 2;
	for (int i = 0; i < n; i++) {
		cin >> p[0][i] >> p[1][i];
	}
	ll ans = -inf;
	int x, old;
	if (odd) {
		cin >> x;
		old = p[1][n - 1];
		p[1][n - 1] = max(p[1][n - 1], x);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			if (j > 0) {
				pr[i][j] = pr[i][j - 1];
			}
			pr[i][j] += p[i][j];
		}
	}
	ans = max(ans, pr[0][n - 1]);
	for (int i = 0; i < n; i++) {
		ll res = 0;
		if (i > 0) {
			res = pr[0][i - 1] - pr[1][i - 1];
		}
		ans = max(ans, res + pr[1][n - 1]);
	}
	
	if (odd) {
		p[0][n - 1] += x;
		p[1][n - 1] = old;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				if (j > 0) {
					pr[i][j] = pr[i][j - 1];
				}
				if (j == 0) {
					pr[i][j] = 0;
				}
				pr[i][j] += p[i][j];
			}
		}
		ll tmp = -inf;
		for (int i = 0; i < n - 1; i++) {
			ll zero = 0;
			if (i > 0) {
				zero = pr[0][i - 1];
			}
			ll one = 0;
			if (i > 0) {
				one = pr[1][i - 1];
			}
			ans = max(ans, pr[0][n - 1] - pr[0][i] + max(zero, one + tmp));
			ll res = 0;
			if (i > 0) {
				res = pr[0][i - 1] - pr[1][i - 1];
			}
			tmp = max(tmp, res);
		}
	}
	cout << ans;
	return 0;
}
