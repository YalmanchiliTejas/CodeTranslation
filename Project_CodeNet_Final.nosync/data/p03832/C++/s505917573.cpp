#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);
}
#else
#define trace(...)
#endif

typedef pair <int, int> pii;
typedef long long ll;
typedef vector <vector <ll>> matrix;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 1005;

int n, a, b, c, d;
int dp[maxn][maxn];
ll fact[maxn];

ll modpow(ll a, ll b) {
	ll x = 1, y = a;
	while (b) {
		if (b & 1) {
			x = (x * y) % mod;
		}
		y = (y * y) % mod;
		b /= 2;
	}
	return x;
}

int solve(int x, int y) {
	if (x == 0) {
		return 1;
	}
	if (y > b) {
		return 0;
	}
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	int ret = solve(x, y + 1);
	for (int i = c; i <= d && (i * y) <= x; i++) {
		int z = i * y;
		int tmp = (modpow(fact[i], mod - 2) * fact[x]) % mod;
		int inv = modpow(fact[y], i);
		tmp = (1LL * tmp * modpow(inv, mod - 2)) % mod;
		tmp = (1LL * tmp * modpow(fact[x - z], mod - 2)) % mod;
		assert(tmp >= 0);
		ret = (ret + (1LL * tmp * solve(x - (i * y), y + 1)) % mod) % mod;
	}
	return dp[x][y] = ret;
}

int main() {
	// freopen("i.txt", "r", stdin);
	// freopen("o.txt", "w", stdout);
	memset(dp, -1, sizeof(dp));
	fact[0] = 1;
	for (int i = 1; i < maxn; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	int ans = solve(n, a);
	printf("%d\n", ans);
	return 0;
}
