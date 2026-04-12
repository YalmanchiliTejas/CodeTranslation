#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;
const int MOD = 1e9 + 7;

int n, m, k;
int fact[N], invfact[N];

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD-2, MOD);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=MOD;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
}

int nCr(int x, int y)
{
	if(y>x)
		return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=MOD;
	num*=invfact[x-y];
	num%=MOD;
	return num;
}


int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	precompute();
	int ans = 0;
	int always = nCr(n * m - 2, k - 2);
	for(int dist = 1; dist <= n - 1; dist++)
	{
		int cur = dist;
		int pairs = m * m;
		pairs %= MOD;
		pairs *= (n - dist);
		pairs %= MOD;
		cur *= pairs;
		cur %= MOD;
		cur *= always;
		cur %= MOD;
		ans += cur;
		ans %= MOD;
	}
	for(int dist = 1; dist <= m - 1; dist++)
	{
		int cur = dist;
		int pairs = n * n;
		pairs %= MOD;
		pairs *= (m - dist);
		pairs %= MOD;
		cur *= pairs;
		cur %= MOD;
		cur *= always;
		cur %= MOD;
		ans += cur;
		ans %= MOD;
	}
	cout << ans;
	return 0;
}