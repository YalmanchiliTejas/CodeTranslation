#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005,mo = int(1e9) + 7;

int cr[maxn][maxn],fac[maxn],rfac[maxn],f[maxn][maxn],n,a,b,c,d;

int pow(int a,int b)
{
	int tmp = 1;
	for(;b;b >>= 1,a = a * 1ll * a % mo)
		if (b & 1) tmp = tmp * 1ll * a % mo;
	return tmp;
}

int main()
{
	cin >> n >> a >> b >> c >> d;
	for(int i = 0;i <= n;i ++)
	{
		cr[i][0] = 1;
		for(int j = 1;j <= i;j ++)
			cr[i][j] = (cr[i - 1][j - 1] + cr[i - 1][j]) % mo;
	}
	fac[0] = 1;
	for(int i = 1;i <= n;i ++) fac[i] = fac[i - 1] * 1ll * i % mo,rfac[i] = pow(fac[i],mo - 2);
	f[0][0] = 1;
	for(int i = 0;i <= b - a;i ++)
		for(int s = 0;s <= n;s ++)
			if (f[i][s])
			{
				int v = i + a;
				f[i + 1][s] = (f[i + 1][s] + f[i][s]) % mo;
				for(int k = 1,val = 1;k <= d && s + v * k <= n;k ++)
				{
					val = val * 1ll * cr[n - s - v * (k - 1)][v] % mo;
					if (k >= c) f[i + 1][s + k * v] = (f[i + 1][s + k * v] + f[i][s] * 1ll * val % mo * rfac[k] % mo) % mo;
				}
			}
	cout << f[b - a + 1][n] << endl;
}
