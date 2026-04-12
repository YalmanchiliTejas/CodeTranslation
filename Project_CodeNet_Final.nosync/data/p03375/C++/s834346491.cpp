# include <iostream>
# include <cstdio>
using namespace std;
typedef long long LL;
const int N = 3e3 + 12;
int n;
LL g[N][N],p,pw[N * N],t[N],f[N],ans,fac[N],inv[N];
LL qpow(LL x,LL y,LL mod)
{
	LL ret = 1;
	while(y){if(y & 1LL)ret = ret * x % mod;x = x * x % mod;y >>= 1LL;}
	return ret;
}
LL C(int x,int y){return fac[x] * inv[y] % p * inv[x - y] % p;}
int main()
{
  scanf("%d %lld",&n,&p);
  pw[0] = t[0] = fac[0] = 1;
  for(int i = 1;i <= n;i++)t[i] = t[i - 1] * (-1LL),fac[i] = 1LL * i * fac[i - 1] % p;
  inv[n] = qpow(fac[n],p - 2,p);
  for(int i = n - 1;~i;i--)inv[i] = 1LL * inv[i + 1] * (i + 1) % p;
  for(int i = 1;i <= n * n;i++)pw[i] = pw[i - 1] * 2LL % p;
  for(int i = 0;i <= n;i++)
  {
  	g[i][0] = 1;
  	for(int j = 1;j <= i;j++)
  	g[i][j] = (g[i - 1][j - 1] + g[i - 1][j] * (j + 1) % p) % p; 
  }
  for(int i = 0;i <= n;i++)
  {
  	for(int j = 0;j <= i;j++)
  	f[i] = (f[i] + g[i][j] * pw[(n - i) * j] % p) % p;
  	f[i] = f[i] * qpow(2,qpow(2,n - i,p - 1),p) % p;
  }
  for(int i = 0;i <= n;i++)
  ans = (ans + t[i] * C(n,i) % p * f[i] % p + p) % p;
  printf("%lld\n",ans);
}