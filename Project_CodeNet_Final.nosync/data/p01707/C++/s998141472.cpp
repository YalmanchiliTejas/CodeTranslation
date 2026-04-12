#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

class BIT {
private:
	ll N;
	ll bit[303030];
public:
	BIT(ll N) : N(N) {
		REP(i, 303030) bit[i] = 0;
	}

	void add(ll a, ll w) {
		a++;
		for (ll x = a; x <= N; x += x & -x) bit[x] += w;
	}

	ll sum(ll a) {
		a++;
		ll ret = 0;
		for (ll x = a; x > 0; x -= x & -x) ret += bit[x];
		return ret;
	}

	ll sum(ll a, ll b) {
		ll ret = sum(b - 1);
		if(a) ret -= sum(a - 1);
		return ret;
	}
};

ll _pow(ll a, ll n) {
	if(n==0) return 1;
	else {
		ll res = 1;
		ll buf = a;
		while(n>0) {
			if(n%2==1) {
				res *= buf;
				res %= MOD;
			}
			buf *= buf;
			buf %= MOD;
			n/=2;
		}
		return res;
	}
}

/* --------------------------------------- */

ll n, d, x;
// return dCk
ll comb(ll k) {
	ll ret = 1;
	REP(i, k) {
		ret *= (d - i) % MOD; ret %= MOD;
	}
	REP(i, k) {
		ret *= _pow(k - i, MOD - 2); ret %= MOD;
	}
	return ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	while(1) {
		cin >> n >> d >> x;
		if(n == 0 && d == 0 && x == 0) break;
		BIT bit(n + 10);
		vector<ll> cnt(n + 1, 0);
		bit.add(0, 1);
		REP(i, n) {
			for(ll j = n; j >= 0; j--) {
				bit.add(j, -bit.sum(j, j + 1));
				bit.add(j, (bit.sum(max(j - x + 1, 0ll), j) % MOD));
			}
			cnt[i + 1] = bit.sum(n, n + 1);
		}
		ll ans = 0;
		for(ll i = 1; i <= n; i++) {
			ans += comb(i) * cnt[i]; ans %= MOD;
		}
		cout << ans << endl;
	}
 	return 0;
}

/* --------------------------------------- */


