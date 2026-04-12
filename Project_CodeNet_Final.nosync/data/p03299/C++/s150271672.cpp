#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;


ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

int n;

ll h[1200];

vector<ll> vv;
pair<ll, ll> ans[1200];
int en[1200];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> h[i], vv.push_back(h[i]);
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	reverse(vv.begin(), vv.end());
	vv.push_back(0);
	for (int i = 0; i < n; ++i)
		en[i] = 0;
	h[n] = 0;
	for (int it = 0; it < vv.size() - 1; ++it) {
		ll hh = vv[it];
		int st = -1;
		int cnt = 0;
		vector<pair<ll, ll>> cur;
		ll len = vv[it] - vv[it + 1];
		ll gd = 1;
		ll all = 1;
		for (int i = 0; i <= n; ++i) {
			if (en[i] == 1) {
				if (st == -1)
					st = i;
				gd = (gd * ans[i].first) % MOD;
				all = (all * (ans[i].first * 2 + ans[i].second)) % MOD;
			}
			else if (h[i] == hh) {
				if (st == -1)
					st = i;
				++cnt;
			}
			else if (en[i] == 0) {
				if (st != -1) {
					for (int j = st; j < i; ++j)
						en[j] = 2;
					en[st] = 1;
					ans[st].first = gd * pw(2, len) % MOD;
					ans[st].second = (all * pw(2, cnt) % MOD - gd * 2 % MOD + MOD) % MOD;
				}
				gd = all = 1;
				st = -1;
				cnt = 0;
			}
		}
	}
	cout << (ans[0].first + ans[0].second) % MOD;
	return 0;
}


