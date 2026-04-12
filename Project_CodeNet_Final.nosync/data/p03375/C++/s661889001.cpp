#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 3005;

int pw(int x,int k,int mod)
{
	int re=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1)
		re=(ll)re*x%mod;
	return re;
}
int n,phimod,mod;
int f[maxn][maxn],C[maxn][maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%d%d",&n,&mod); phimod=mod-1;
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=0;i<=n;i++) f[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++) f[i][j]=((ll)f[i-1][j]+f[i-1][j-1]+(ll)f[i-1][j]*j%mod)%mod;
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int now=0,oth=pw(2,pw(2,n-i,phimod),mod);
		for(int j=0;j<=i;j++) (now+=(ll)f[i][j]*pw(pw(2,n-i,mod),j,mod)%mod)%=mod;
		now=(ll)now*C[n][i]%mod*oth%mod;
		if(i&1) ans=(ans-now+mod)%mod;
		else ans=(ans+now)%mod;
	}
	printf("%d\n",ans);
	
	return 0;
}
