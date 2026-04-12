#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define p pair<ll,ll>
int main()
{
	int n;
	cin>>n;
	v arr(n+1,-1);
	for (int i=1; i<=n; i++)
		cin>>arr[i];
	vv dp1(n+2,v(n+2,0));
	vv dp2(n+2,v(n+2,0));
	for (int i=n; i>=1; i--)
	{
		for (int j=i; j<=n; j++)
		{
			dp1[i][j]=max(dp2[i+1][j]+arr[i],dp2[i][j-1]+arr[j]);//+arr[i];
			dp2[i][j]=min(dp1[i+1][j]-arr[i],dp1[i][j-1]-arr[j]);
		}
	}
	cout<<dp1[1][n]<<endl;
	return 0;
}