//Badwaper gg
#include<bits/stdc++.h>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
#define pb push_back
#define re register ll
#define fr first
#define sd second
#define FOR(i,a,b) for(re i=a;i<=b;i++)
#define REP(i,a,b) for(re i=a;i>=b;i--)
#define lowbit(x) x&(-x)
#define Z(x) (x>=mod?x-mod:x)
#define N 3010
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int G[N],F[N][N],P[N];
int n,S[N][N],mod,C[N][N];
inline int ksm(int a,int b,int mod)
{
	int ans=1;
	while(b){if(b&1)ans=1LL*ans*a%mod;b>>=1;a=1LL*a*a%mod;}
	return ans;
}
inline int Solve(int i)
{
	int sum=0;
	FOR(x,1,i+1)sum=Z(sum+1LL*S[i+1][x]*F[n-i][x-1]%mod);
	return sum;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),mod=read();
	FOR(i,0,n+1)G[i]=ksm(2,ksm(2,i,mod-1),mod);
	FOR(i,0,n+1)P[i]=ksm(2,i,mod);
	S[0][0]=1;
	FOR(i,1,n+1)
	{
		FOR(j,1,i)S[i][j]=Z(S[i-1][j-1]+1LL*S[i-1][j]*j%mod);
	}
	C[0][0]=1;
	FOR(i,1,n+1)
	{
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=Z(C[i-1][j-1]+C[i-1][j]);
	}
	FOR(i,0,n+1)
	{
		F[i][0]=1;
		FOR(j,1,n+1)F[i][j]=1LL*F[i][j-1]*P[i]%mod;
	}
	int ans=0,c=1;
	FOR(i,0,n){ans=Z(ans+1LL*c*C[n][i]%mod*G[n-i]%mod*Solve(i)%mod);c=mod-c;}
	printf("%d\n",ans);
	return 0;
}
