#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>
 
#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)
 
#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
using namespace std;
 
 
/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
 
int n;
 
int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	vector<ll> st;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		while (true) {
			if (st.size() <= 1) {
				st.push_back(x);
				break;
			}
			else {
				ll a = st[st.size() - 2];
				ll b = st[st.size() - 1];
				if (b >= a && b >= x) {
					st.pop_back();
					st.pop_back();
					x += a - b;
				}
				else {
					st.push_back(x);
					break;
				}
			}
		}
	}
	int l = 0;
	int r = st.size() - 1;
	ll ans = 0;
	int sgn = 1;
	while (l <= r) {
		if (st[l] >= st[r])
			ans += sgn * st[l], ++l;
		else
			ans += sgn * st[r], --r;
		sgn *= -1;
	}
	cout << ans << "\n";
	return 0;
}
 
 