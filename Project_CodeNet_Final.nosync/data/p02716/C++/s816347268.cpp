#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200005;
int n,m=1,val[maxn];
LL f[maxn][2][3];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	if (n&1) m++;
	f[1][1][0]=val[1];
	for (int i=2;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			f[i][0][j]=f[i-1][1][j];
			f[i][1][j]=f[i-1][0][j]+val[i];
			if (j) f[i][0][j]=max(f[i][0][j],f[i-1][0][j-1]);
		}
	printf("%lld\n",max(f[n][0][m-1],f[n][1][m]));
	return 0;
}
