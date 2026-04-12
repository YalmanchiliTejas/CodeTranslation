#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
typedef pair<P, P> PPP;

const ll MOD = 1e9 + 7;
const ll INF = 9e18;
const double DINF = 5e14;
const double eps = 1e-10;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second



struct Fact_combination {
private:
	vector<ll>FACT;
	vector<ll>IFACT;
	ll N;
public:
	ll extgcd(ll a, ll b, ll &x, ll &y) {
		ll g = a;
		x = 1;
		y = 0;
		if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
		return g;
	}
	ll invMod(ll a, ll m) {
		ll x, y;
		if (extgcd(a, m, x, y) == 1) return (x + m) % m;
		else return 0;
	}
	ll mod_pow(ll x, ll n) {
		ll res = 1;
		while (n > 0) {
			if (n & 1) res = res * x%MOD;
			x = x * x%MOD;
			n >>= 1;
		}
		return res;
	}
	void inverse(ll n) {
		N = n;
		FACT.resize(N + 1);
		IFACT.resize(N + 1);
		FACT[0] = 1;
		IFACT[0] = 1;
		for (int i = 1;i <= N;i++) {
			FACT[i] = FACT[i - 1] * i % MOD;
			IFACT[i] = invMod(FACT[i], MOD);
		}
	}
	ll combi(ll n, ll r) {
		if (n < 0 || r < 0 || r > n)return 0;
		if (r > n / 2)r = n - r;
		return FACT[n] * IFACT[n - r] % MOD*IFACT[r] % MOD;
	}
};



int n, a, b, c, d;
ll dp[2][1010];
vector<int>v[1010];


int main() {
	cin >> n >> a >> b >> c >> d;
	dp[0][0] = 1;
	Fact_combination fc;
	fc.inverse(n);
	for (int i = a;i <= b;i++) {
		for (int j = 1;j <= d;j++) {
			if (i*j > n)continue;
			v[i].eb(i);
		}
	}
	for (int i = a;i <= b;i++) {
		queue<P>q;
		for (int j = 0;j < n;j++) {
			if (dp[0][j])q.push(P(j, dp[0][j]));
		}
		for (int u = 0;u < v[i].size();u++) {
			int sz = q.size();
			while (sz) {
				P p = q.front();
				q.pop();
				sz--;
				if (p.fr + v[i][u] > n)continue;
				q.push(P(p.fr + v[i][u], ((p.sc*fc.combi(n - p.fr, v[i][u])%MOD * fc.invMod(u + 1,MOD))) % MOD));
				if (u + 1 < c)continue;
				dp[1][p.fr + v[i][u]] += p.sc * fc.combi(n - p.fr, v[i][u])%MOD * fc.invMod(u + 1, MOD) % MOD;
				dp[1][p.fr + v[i][u]] %= MOD;
			}
			for (int j = 0;j <= n;j++) {
				dp[1][j] += dp[0][j];
				dp[1][j] %= MOD;
				dp[0][j] = dp[1][j];
				dp[1][j] = 0;
			}
		}
	}
	cout << dp[0][n]%MOD << endl;
	return 0;
}