/* https://codeforces.com/contest/1360/problem/H */
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using vs = vector<string>;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;
using ld = double;

#define f first
#define s second 
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define pb push_back
#define	lb lower_bound
#define	ub upper_bound
#define	sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define ins insert

ll N, X, M;
vector<ll> repeat;
ll ans = 0;

void fun(ll total, ll idx) {
	if (find(all(repeat), total) != repeat.end()) {
		int i = 0;
		for (;;++i) {
			if (total == repeat[i]) break;
			ans += repeat[i];
		}

		int pre_cycle_terms = i;
		ll cycle_sum= accumulate (all(repeat), -ans);
		ll cycle_terms = repeat.size() - i;
		ll x = (N - i) / cycle_terms;
		ll y = (N - i) % cycle_terms;

		ans = accumulate (repeat.begin() + i, repeat.begin() + i + y, ans + cycle_sum * x);
		return;
	}

	if (idx == N) {
		repeat.pb(total);
		ans = accumulate(all(repeat), 0);
		return;
	}

	repeat.pb(total);
	fun((total * total) % M, idx + 1);
}

int main() {
	cin>>N>>X>>M;
	fun(X, 1);
	cout<<ans<<endl;
	return 0;
}
