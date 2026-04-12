#include<map>
#include<set>
#include<bitset>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define SIZE(a) ll(a.size())
#define vll vector<ll> 
#define BIT(n) (ll(1)<<n)
#define UNIQUE(v) v.erase(unique(v.begin(),v.end()),v.end()) 
#define UNIQUE_ARRAY(a,n) n = unique(a + 1, a + x + 1) - a - 1
#define SORT(a,n) sort(a+1,a+n+1)
#define SORT_O(a,n,order) sort(a+1,a+n+1,order)
#define PER(i,y,x) for(ll i=y;i>=x;i--)
typedef long long ll;
using namespace std;
/*
struct point
{
long long dist; long long name;
bool operator<(const point& rhs) const {
return dist > rhs.dist;
}
};
*/
ll MOD;
ll const MAX = 5000;
ll mod_p(ll x, ll y) {
	return (x + y + MOD) % MOD;
}

ll mod_m(ll x, ll y) {
	return x * y%MOD;
}

ll minusone(ll x) {
	if (x % 2 == 0) {
		return 1;
	}
	else return -1;
}

ll fuct[MAX];
ll inv_fuct[MAX];
ll pow22[MAX];
// 2 4 16 256
ll mod_pow(ll x, ll t) {
	if (t == 0) {
		return 1;
	}
	else {
		ll s = mod_pow(x, t / 2);
		if (t % 2 == 1) {
			return s * s%MOD*x%MOD;
		}
		else {
			return s * s %MOD;
		}
	}
}
ll mod_inv(ll x) {
	return mod_pow(x, MOD - 2);
}

ll comb(ll x, ll y) {
	return mod_m(fuct[x], mod_m(inv_fuct[y], inv_fuct[x - y]));
}
void init(ll n) {
	fuct[0] = inv_fuct[0] = 1;
	REP(i, 1, n) {
		fuct[i] = mod_m(fuct[i - 1], i);
		inv_fuct[i] = mod_inv(fuct[i]);
	}
	pow22[0] = 2;
	REP(i, 1, n) {
		pow22[i] = mod_m(pow22[i - 1], pow22[i - 1]);
	}
}
ll T[MAX] = {};
ll S[MAX][MAX];

void solve_s(ll n) {
	S[1][1] = S[1][0] = 1;
	REP(j, 2, n) {
		S[1][j] = 0;
	}
	REP(i, 2, n) {
		S[i][0] = 1;
		REP(j, 1, n) {
			S[i][j] = mod_p(S[i - 1][j] * (j+1), S[i - 1][j - 1]);
		}
	}
}

void solve_t(ll n) {
	solve_s(n);
	ll g = 1;
	REP(i, 1, n) {
		g = g * 2 % MOD;
	}
	T[0] = pow22[n];
	REP(i, 1, n) {
		T[i] = 0;
		ll q = mod_pow(2, n - i);
		ll t = 1;
		REP(j, 0, i) {
			T[i] = mod_p(T[i],mod_m(S[i][j],t));
			t = mod_m(t, q);
		}
		T[i] = mod_m(T[i], pow22[n - i]);
	}
}

int main() {
	ll n;
	cin >> n >> MOD;
	init(n);
	solve_t(n);
	ll ans = 0;
	REP(i, 0, n) {
		ans = mod_p(ans, minusone(i)*mod_m(comb(n, i), T[i]));
	}
	cout << ans << endl;
}

