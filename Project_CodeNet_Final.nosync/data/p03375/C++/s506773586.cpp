#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <bitset>
#include <string>
#include <cmath>
#include <set>
#include <map>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define ev g[i].y
#define eps 1e-10
#define fr first
#define sd second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
const int N = 3005;
int n, mod;
ll ans, res, f[N][N], c[N][N];
ll power(ll x, ll y, int mod = mod) {
	// x %= mod, y %= mod;
	ll z = 1;
	while (y) {
		if (y & 1) (z *= x) %= mod;
		y >>= 1; (x *= x) %= mod;
	}
	return z;
}
int main()
{
	cin >> n >> mod;
	ans = power(2, power(2, n, mod - 1));
	// cout <<0<<" "<< ans<<endl;
	c[0][0] = 1;
	Rep(i, 1, n) {
		c[i][0] = 1;
		Rep(j, 1, i) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	f[0][0] = 1;
	Rep(i, 1, n) {
		ll k = power(2, n - i), pk = 1, res = 0;
		Rep(j, 0, i) {
			f[i][j] = f[i - 1][j] * (j + 1) % mod;
			if (j) (f[i][j] += f[i - 1][j - 1]) %= mod;
		 	// cout <<i<<" "<< j<<" "<<f[i][j]<<endl;
			(res += f[i][j] * pk % mod) %= mod;
		 	pk = pk * k % mod;
		}
		res = res * c[n][i] % mod;
		res = res * power(2, power(2, n - i, mod - 1)) % mod;
		if (i & 1) ans -= res;
		else ans += res;
		// cout <<i<<" "<< res<<" "<<ans<<endl;
		ans %= mod;
	}
	cout << (ans % mod + mod) % mod << endl;

	return 0;
}