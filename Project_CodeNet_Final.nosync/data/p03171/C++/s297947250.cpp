#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3010;
const ll INF=1e18;
int a[N];
ll dp[N][N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch&15),ch=getchar();
	return x*f;
}
int main()
{
	int n=read();
	for (register int i=1;i<=n;++i) a[i]=read();
	for (register int i=1;i<=n;++i) dp[i][i]=a[i];
	for (register int i=n;i>=1;--i)
	  for (register int j=i+1;j<=n;++j)
	    dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
	printf("%lld\n",dp[1][n]);
	return 0;
}