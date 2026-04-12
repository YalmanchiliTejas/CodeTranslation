#include<bits/stdc++.h>
#include<bits/extc++.h>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using namespace __gnu_pbds;

typedef tree< int, null_type, less< int >, rb_tree_tag, tree_order_statistics_node_update> ost;
// name.find_by_order(x) or name.order_of_key(x)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;

void yes() {printf("YES\n");}
void no() {printf("NO\n");}

int dx4[] = {-1, 1, 0, 0};
int dy4[] = {0, 0, -1, 1};
int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int maxn = 2e5 + 5, maxv = 2e6 + 5;
int MOD = 1e9 + 7;

int mult(ll a, ll b) {return (a * b) % MOD;}
int pot(int n, int k) {
	int ret = 1, pot = n;
	for(;k > 0;k >>= 1, pot = mult(pot, pot)) 
		ret = mult(ret, (k & 1) ? pot : 1);
	return ret;
}
int divide(int a, int b) {return mult(a, pot(b, MOD - 2));}
int add(int a, int b) {a += b;if(a >= MOD) a -= MOD;return a;}
int sub(int a, int b) {a -= b;if(a < 0) a += MOD;return a;}

vector<int> fact;
void calc_fact(int n) {
	fact = vector<int>(n + 1, 1);
	for(int i = 1;i <= n;i++) fact[i] = mult(fact[i - 1], i);
}
int choose(int n, int k) {return divide(fact[n], mult(fact[n - k], fact[k]));}

bool prime(ll a) {
	if (a == 1) return 0;
	for(ll i = 2;i * i <= a;i++) 
		if (a % i == 0) return 0;
	return 1;
}

ll gcd(ll a, ll b) {return (b == 0 ? a : gcd(b, a % b));}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

ll phi(ll x) {
	double ret = x;
	for(ll i = 2;i * i <= x;i++) {
		if (x % i) continue;
		ret *= (1.0 - 1.0 / (double)i);
		while (x % i == 0) x /= i;
	}
	if (x > 1) ret *= (1.0 - 1.0 / (double)x );
	return (ll)ret;
}

void solve() {
	ll n;
	int x, m;
	scanf("%lld %d %d", &n, &x, &m);
	MOD = m;
	vi vis(m, 0);
	vi v;
	int y = x, poc = -1;
	while(1) {
		if(vis[y]) {poc = y;break;}
		vis[y] = 1;
		v.pb(y);
		y = mult(y, y);
	}
	int pl = 0;
	for(int i = 0;i < (int)v.size();i++) if(v[i] == poc) pl = i;
	ll ans = 0;
	if(n < (int)v.size()) {
		for(int i = 0;i < n;i++) ans += (ll)v[i];
		printf("%lld\n", ans);
		return;
	}
	
	for(int i = 0;i < pl;i++) ans += (ll)v[i];
	ll cycle = 0;
	for(int i = pl;i < (int)v.size();i++) cycle += (ll)v[i];
	n -= pl;
	int sz = (int)v.size() - pl;
	ans += (ll)cycle * (n / sz);
	n %= sz;
	for(int i = pl;i < pl + n;i++) ans += (ll)v[i];
	printf("%lld\n", ans);
}

int main() {
	int t = 1;
	//scanf("%d", &t);
	while(t--) solve();
	return 0;
}
