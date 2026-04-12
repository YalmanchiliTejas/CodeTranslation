#include"bits/stdc++.h"
using namespace std;
int n,a[3001];
long long f[3001][3001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(n%2)
			f[i][i]=a[i];
		else
			f[i][i]=-a[i];
	}
	for(int j=1;j<n;j++)
		for(int i=1;i+j<=n;i++)
		{
			if((j+(n%2))%2)
				f[i][i+j]=max(f[i+1][i+j]+a[i],f[i][i+j-1]+a[i+j]);
			else
				f[i][i+j]=min(f[i+1][i+j]-a[i],f[i][i+j-1]-a[i+j]);
		}
	printf("%lld",f[1][n]);
}