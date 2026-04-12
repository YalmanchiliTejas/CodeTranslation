#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll f[3010][3010],a[3010];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		f[i][i]=a[i];
	}
	for (int l=1;l<n;l++)
	{
		for (int i=1;i+l<=n;i++)
		{
			int j=i+l;
			f[i][j]=max(a[i]-f[i+1][j],a[j]-f[i][j-1]);
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
