#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll p = 1e9+7;

ll n, h[105], dp[105][105], k;
map<int, int> m;
vector<int> v;

ll exp(ll x, ll k) {
	if (k < 0)
		return 0;
	if (k == 0)
		return 1;
	if (k%2 == 1)
		return x*exp(x, k-1)%p;
	ll y = exp(x, k/2);
	return y*y%p;
}

//alternate in first h1 squares
//does not alternate in first h2 squares
//total length x
ll ctalt(ll h1, ll h2, ll x) {
	if (h1 >= h2)
		return 0;
	ll ct1 = 0, ct2 = 0;
	if (h1 == 0)
		ct1 = exp(2, x);
	else
		ct1 = 2*exp(2, x-h1);
	if (h2 == 0)
		ct2 = exp(2, x);
	else
		ct2 = 2*exp(2, x-h2);
	return (p+ct1%p-ct2%p)%p;
}

int main() {
	cin >> n;
	v.push_back(0);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		if (m.count(h[i]) > 0)
			continue;
		m[h[i]] = 1;
		v.push_back(h[i]);
	}
	sort(v.begin(), v.end());
	k = v.size();
	v.push_back(1000000005);

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			for (int j = 0; j < k; ++j) {
				dp[i][j] = ctalt(v[j], v[j+1], h[i]);
			}
			continue;
		}

		int t = 0, t1 = 0;
		for (int j = 0; j < k; ++j) {
			if (h[i] == v[j])
				t = j;
			if (h[i-1] == v[j])
				t1 = j;
		}

		for (int j = 0; j <= t1; ++j) {
			if (h[i] <= h[i-1]) {
				if (v[j] >= h[i])
					dp[i][t] = (dp[i][t] + 2*dp[i-1][j])%p;
				else
					dp[i][j] = (dp[i][j] + dp[i-1][j])%p;
			} else {
				if (j < t1) {
					dp[i][j] = (dp[i][j] + dp[i-1][j]*exp(2, h[i]-h[i-1]))%p;
				} else {
					ll x = dp[i-1][j];
					for (int jj = t1; jj < k; ++jj)
						dp[i][jj] = (dp[i][jj] + x*ctalt(v[jj], v[jj+1], h[i]))%p;
				}
			}
		}
	}

	ll ans = 0;
	for (int j = 0; j < k; ++j)
		ans = (ans + dp[n-1][j])%p;
	cout << ans << endl;
}