//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 2e5 + 5;
const double eps = 1e-9;
ll fac[MAXN], ifac[MAXN];

ll pw(ll a, ll b) {
	ll r = 1;
	while (b)
		if (b & 1)
			r = (r*a) % MOD, b--;
		else
			a = (a*a) % MOD, b /= 2ll;
	return r;
}

inline ll inv(ll x) {
	return pw(x, MOD-2);
}

inline ll bin(ll n, ll k) {
	return (fac[n] * ifac[k] % MOD) * ifac[n-k] % MOD;
}

int main() {
	fac[0] = ifac[0] = 1;
	for (ll i = 1; i < MAXN; i++)
		fac[i] = fac[i-1] * i % MOD, ifac[i] = inv(fac[i]);
	ll n, m, k; scanf("%lld %lld %lld", &n, &m, &k);
	ll ans = 0, dx = 0, dy = 0;
	for (ll i = 1; i < n; i++)
		dx = (dx + (i * (n-i) % MOD)) % MOD;
	dx = dx * (m*m%MOD) % MOD;
	for (ll i = 1; i < m; i++)
		dy = (dy + (i * (m-i) % MOD)) % MOD;
	dy = dy * (n*n%MOD) % MOD;
	ans = (dx+dy)%MOD;
	ans = (ans*bin(n*m-2, k-2)) % MOD;
	prl(ans);
    return 0;
}
