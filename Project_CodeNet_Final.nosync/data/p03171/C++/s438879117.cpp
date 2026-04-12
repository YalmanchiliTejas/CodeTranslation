#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3005;
ll a[maxn],val[maxn][maxn];
void fl()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int main()
{
//    fl();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		val[i][i]=(n%2?a[i]:-a[i]);
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int l=i,r=i+len-1;
			if(n%2!=len%2) 
				val[l][r]=min(val[l+1][r]-a[l],val[l][r-1]-a[r]);
			else val[l][r]=max(val[l+1][r]+a[l],val[l][r-1]+a[r]);
		}
	printf("%lld\n",val[1][n]);
	return 0;
}
