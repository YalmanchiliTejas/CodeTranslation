#include "bits/stdc++.h"

using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

#define int ll
typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define in(x, a, b) a <= x && x < b
const int inf = 1000000001;
const ll INF = 2e18;
//const ll MOD = 1000000007;
//const ll mod = 1000000009;
const double pi = 3.14159265358979323846;
#define Sp(p) cout<<setprecision(15)<< fixed<<p <<endl;
int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };


ll n, MOD;
const int MAXN = 3010;
vl ways(MAXN);
vll ways2(MAXN, vl(MAXN));

vll secondStirling(MAXN, vl(MAXN, 0));
vl fact(MAXN);
vl rfact(MAXN);

ll mod_pow(ll x, ll p, ll M = MOD) {
	ll a = 1;
	while (p) {
		if (p % 2)
			a = a*x%M;
		x = x*x%M;
		p /= 2;
	}
	return a;
}

ll mod_inverse(ll a, ll M = MOD) {
	return mod_pow(a, M - 2, M);
}

void set_fact(ll n, ll M = MOD) {
	fact[0] = fact[1] = rfact[0] = rfact[1] = 1;
	for (ll i = 2; i <= n; i++) {
		fact[i] = i * fact[i - 1] % M;
		rfact[i] = mod_inverse(fact[i], M);
	}
}

ll nCr(ll n, ll r, ll M = MOD) {
	ll ret = fact[n];
	ret = (ret*rfact[r]) % M;
	ret = (ret*rfact[n - r]) % M;
	return ret;
}



void setSecondStirling(ll n, ll M = MOD) {
	secondStirling[0][0] = 1;
	rep1(i, n) {
		rep(j, i + 1) {
			if (j == i) {
				secondStirling[i][j] = 1;
			}
			else if (j == 0) {
				secondStirling[i][j] = 1;
			}
			else {
				secondStirling[i][j] = (secondStirling[i - 1][j - 1] + (ll)(j + 1)*secondStirling[i - 1][j] % M) % M;
			}
		}
	}
}

vl memo1(10000000, -1), memo2(10000000, -1);

signed main() {
	cin >> n >> MOD;
	setSecondStirling(n);
	set_fact(n);
	rep(i, n + 1) {
		rep(j, i + 1) {
			ll temp = secondStirling[i][j];
			if (memo1[(n - i)*j] == -1) {
				memo1[(n - i)*j] = mod_pow(2, (n - i)*j);
			}
			temp *= memo1[(n - i)*j];
			temp %= MOD;
			if (memo2[n - i] == -1) {
				memo2[n - i] = mod_pow(2, n - i, MOD - 1);
			}
			temp *= mod_pow(2, memo2[n - i]);
			temp %= MOD;
			ways2[i][j] = temp;
		}
		//cout << endl;
	}
	rep(i, n + 1) {
		//DEBUG(i);
		rep(j, i + 1) {
			ways[i] += ways2[i][j];
			ways[i] %= MOD;
		}
		//DEBUG(ways[i]);
	}
	ll ans = 0;
	ll fugou = 1;
	rep(i, n + 1) {
		ans += fugou*nCr(n, i) % MOD *ways[i] % MOD;
		ans %= MOD;
		fugou *= -1;
	}
	while (ans < 0) {
		ans += MOD;
	}
	cout << ans << endl;
}