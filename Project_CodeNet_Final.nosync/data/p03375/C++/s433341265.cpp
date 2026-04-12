#include <bits/stdc++.h>

using namespace std;

int n,m;

int qpow(int base,int tms,int mod = m)
{
	int tmp = 1;
	while(tms)
	{
		if(tms & 1) tmp = tmp * 1ll * base % mod;
		base = base * 1ll * base % mod;
		tms >>= 1;
	}
	return tmp;
}

int C[3050][3050];
int S[3050][3050];

int main()
{
	scanf("%d%d",&n,&m);
	C[0][0] = S[0][0] = 1;
	for(int i = 1;i <= 3001; ++ i)
	{
		C[i][0] = 1;
		for(int j = 1;j <= i; ++ j)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % m,
			S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * 1ll * j % m) % m;
	}
	long long ans = 0;
	for(int i = 0;i <= n; ++ i)
	{
		int fg = (i & 1) ? m - 1 : 1;
		long long xs = C[n][i] * 1ll * qpow(2,qpow(2,n - i,m - 1)) % m;
		long long su = 0;
		for(int j = 0;j <= i; ++ j)
			su = (su + S[i + 1][j + 1] * 1ll * qpow(2,(n - i) * j) % m) % m;
		ans = ans + fg * 1ll * xs % m * su % m;
		ans %= m;
	}
	printf("%lld\n",ans);
}