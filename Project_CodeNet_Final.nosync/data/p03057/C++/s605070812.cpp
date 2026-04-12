#include<cstdio>
#include<cstring>
#include<iostream>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=2e5+50;
int n,m;
int f[maxn];
int s[maxn];
char S[maxn];
inline int add(int x)
{
	return x>=mod?x-mod:x;
}
inline int dec(int x)
{
	return x<0?x+mod:x;
}
void dp(int L)
{
	f[1]=s[1]=1;
	for(int i=2;i<=n;++i)
	{
		f[i]=dec(s[i-1]-s[max(0,i-L-2)]);
		s[i]=add(s[i-1]+f[i]);
	} 
}
int solve()
{
	if(S[1]=='B')
	{
		for(int i=1;i<=m;++i)
		{
			S[i]=S[i]=='R'?'B':'R'; 
		}
	}
	int an=0,k=1,L=n;
	while(k<m&&S[k+1]=='R')
	{
		++k;
	}
	if(k==m)
	{
		static int f[maxn][2];
		memset(f,0,sizeof(f)); 
		f[1][0]=1;
		for(int i=1;i<n;++i)
		{
			f[i+1][0]=add(f[i][0]+f[i][1]);
			f[i+1][1]=add(f[i][0]);
		}
		an=add(an+f[n][0]);
		an=add(an+f[n][1]);
		memset(f,0,sizeof(f));
		f[1][1]=1;
		for(int i=1;i<n;++i)
		{
			f[i+1][0]=add(f[i][0]+f[i][1]);
			f[i+1][1]=add(f[i][0]);
		}
		an=add(an+f[n][0]);
		return an;
	}
	if(n&1) return 0;
	L=k&1?k:k+1;
	for(int i=k+1,j;i<=m;i=j+1)
	{
		j=i;
		while(j<=m&&S[j]!='B')
		{
			++j;
		}
		if(j==m+1) continue;
		int _k=j-i;
		if(_k&1) L=min(L,_k);
	}
	n>>=1,L>>=1;
	dp(L);
	for(int i=n;i>=1;--i)
	{
		if(n-i>L) break;
		an=(an+(ll)(n-i+1)*f[i])%mod;
	}
	an=add(an<<1);
	return an;
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",S+1);
	printf("%d\n",solve());
	return 0;
} 