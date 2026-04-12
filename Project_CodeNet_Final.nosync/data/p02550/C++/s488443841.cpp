#include "bits/stdc++.h"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using ll = long long int;

ll mpow(ll a, ll n, ll mod)
{
	ll r = 1;
	while (n) {
		if (n&1) r = r*a%mod;
		a = a*a%mod;
		n >>= 1;
	}
	return r;
}

const int N = 1e6+5;
int Div[N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	ll n, x, m; cin >> n >> x >> m;
	vector<int> mark(m+1);
	vector<ll> seq;
	int st = -1, done = 0;
	ll sum = 0;
	while (1) {
		if (mark[x] == 0) {
			sum += x;
			++done;
			mark[x] = done;
			seq.push_back(x);
			x = (x*x)%m;
			if (done == n) return cout << sum << '\n', 0;
		}
		else {
			st = mark[x];
			break;
		}
	}
	ll ans = 0;
	for (int i = 1; i < st; ++i) {
		ans += seq[i-1];
		--n;
	}
	int cyc_len = seq.size()+1-st;
	ll cycle = 0;
	for (int i = st; i <= (int)seq.size(); ++i)
		cycle += seq[i-1];
	ll times = n/cyc_len;
	ans += cycle*times;
	n %= cyc_len;
	for (int i = 0; i < n; ++i)
		ans += seq[st-1+i];
	cout << ans << '\n';
	// k before + n*cycle + remainder

}