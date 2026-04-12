#include <bits/stdc++.h>
using namespace std;
long long f[3001][3001];
int a[3001];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(n%2==0)
			f[i][i]=-a[i];
		else
			f[i][i]=a[i];	
	}
	for(j=1;j<n;j++)
	{
		for(i=1;i+j<=n;i++)
		{
			if(j%2==n%2)
				f[i][i+j]=min(f[i+1][i+j]-a[i],f[i][i+j-1]-a[i+j]);
			else if(j%2!=n%2)
				f[i][i+j]=max(a[i]+f[i+1][j+i],f[i][i+j-1]+a[i+j]);
		}
	}
	printf("%lld",f[1][n]);
	return 0;
}