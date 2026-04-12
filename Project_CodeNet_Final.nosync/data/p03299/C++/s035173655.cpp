#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1010, inf=1e9, mod=1e9+7;
int n, N;
int h[maxn], b[maxn], f[maxn][maxn];

template<typename T>
inline void read(T &k)
{
	int f=1; k=0; char c=getchar();
	while(c<'0' || c>'9') c=='-'&&(f=-1), c=getchar();
	while(c<='9' && c>='0') k=k*10+c-'0', c=getchar();
	k*=f;	
}

inline int power(int a, int b)
{
	if(b<0) return 1;
	int ans=1;
	for(;b;b>>=1, a=1ll*a*a%mod)
	if(b&1) ans=1ll*a*ans%mod;
	return ans;
}
 
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(h[i]), b[++N]=h[i];
	sort(b+1, b+1+N); N=unique(b+1, b+1+N)-b-1;
	for(int i=1;i<=n;i++) h[i]=lower_bound(b+1, b+1+N, h[i])-b;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0]=2ll*f[i-1][0]%mod;
		for(int j=h[i]+1;j<=h[i-1];j++) f[i][0]=(f[i][0]+2ll*f[i-1][j])%mod;
		int sj=min(h[i], h[i-1]);
		for(int j=1;j<=sj;j++)
		f[i][j]=1ll*f[i-1][j]*power(2, b[h[i]]-b[h[i-1]])%mod;
		for(int j=h[i-1]+1;j<=h[i];j++)
		if(j>1) f[i][j]=(f[i][j]+1ll*f[i-1][0]*(power(2, b[j]-b[j-1])-1+mod)*2%mod*power(2, b[h[i]]-b[j]))%mod;
		else f[i][j]=(f[i][j]+1ll*f[i-1][0]*(power(2, b[j]-1)-1)*2%mod*power(2, b[h[i]]-b[j]))%mod;
	}
	int ans=0;
	for(int i=0;i<=N;i++) ans=(ans+f[n][i])%mod;
	printf("%d\n", ans);
}