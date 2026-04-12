#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define GET_BIT(n, i) (((n) & (1LL << ((i)-1))) >> ((i)-1)) // i start from 1
#define SET_BIT(n, i) ((n) | (1LL << ((i)-1)))
#define CLR_BIT(n, i) ((n) & ~(1LL << ((i)-1)))
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
void myInit();
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const int MOD = 1000000007;
const int N = 3e5, M = N;
//=========TQR==============
vi g[N];

int main() {
	myInit();
	FIO;
	int n, i;
	cin >> n;
	vl a(n), pre(n);

	unsigned ll ans = 0;
	fo(i, n) {
		cin >> a[i];
		if (i == 0)
			pre[i] = a[i];
		else
			pre[i] = (pre[i - 1] + a[i]) % MOD;
	}
	Fo(i, 1, n) {
		ans = (ans + (a[i] * pre[i - 1]) % MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}

void myInit() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int mpow(int base, int exp) {
	base %= MOD;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((ll)result * base) % MOD;
		base = ((ll)base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

void ipgraph(int n, int m) {
	int i, u, v;
	while (m--) {
		cin >> u >> v;
		g[u - 1].pb(v - 1);
		g[v - 1].pb(u - 1);
	}
}

void dfs(int u, int par) {
	for (int v : g[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
}