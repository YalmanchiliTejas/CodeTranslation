#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e3 + 10;
int n, a, b, c, d;
ll f[maxn][maxn];
ll fac[maxn], inv[maxn], facinv[maxn], facinvi[maxn][maxn];
void pre()
{
	fac[0] = 1; for(int i = 1; i < maxn; ++i) fac[i] = fac[i - 1] * i % mod;
	inv[1] = 1; for(int i = 2; i < maxn; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	facinv[0] = 1; for(int i = 1; i < maxn; ++i) facinv[i] = facinv[i - 1] * inv[i] % mod;
	for(int i = 0; i < maxn; ++i) facinvi[i][0] = 1;
	for(int i = 0; i < maxn; ++i) for(int j = 1; j < maxn; ++j) facinvi[i][j] = facinvi[i][j - 1] * facinv[i] % mod;
}
ll C(int n, int m) { return n < m ? 0 : fac[n] * facinv[m] % mod * facinv[n - m] % mod;}
int main()
{
	pre();
	cin >> n >> a >> b >> c >> d;
	f[a - 1][0] = 1;
	for(int i = a; i <= b; ++i)
		for(int j = 0; j <= n; ++j)
		{
			f[i][j] = f[i - 1][j];
			for(int k = c; k <= d && j >= i * k; ++k)
				f[i][j] = (f[i][j] + f[i - 1][j - i * k] * fac[j] % mod * facinv[j - i * k] % mod * facinvi[i][k] % mod * facinv[k] % mod) % mod;
		}
	cout << f[b][n] << endl;
	return 0;
}
		
			
	