#include <bits/stdc++.h>
using namespace std;

#define int long long

int n,a[3005];
int f[3005][3005];

signed main()
{
	cin>>n;
	for(int i=1;i<=n;cin>>a[i++]);
	for(int i=1;i<=n;f[i][i]=a[i],i++);
	for(int i=2;i<=n;i++)
		for(int l=1;l+i-1<=n;l++)
		{
			int r=l+i-1;
			f[l][r] = max(a[l]-f[l+1][r],-f[l][r-1]+a[r]);
		}
	cout<<f[1][n]<<endl;
	
	return 0;
}