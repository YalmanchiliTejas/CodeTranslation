#include<bits/stdc++.h>
#define ll  long long int
using namespace std;
int ans[3000][3000];
ll foo(ll a[],int i,int j)
{
	cout<<i<<" "<<j<<endl;
	if(j==(i+1)) return max(a[i],a[j]);
	if(i==j) return a[i];
	if(ans[i][j] !=(-1)) return ans[i][j];

	ans[i][j] = max(a[i]+ min(foo(a,i+1,j-1),foo(a,i+2,j)) , a[j] + min(foo(a,i,j-2),foo(a,i+1,j-1)));
	//cout<<i<<" "<<j<<" "<<ans[i][j]<<endl;
	return ans[i][j];
}
int  main()
{
	memset(ans,(-1),sizeof(ans));
	ll n;
	cin>>n;
	ll a[n],sum=0;
	ll dpX[n][n],dpY[n][n];
	for(ll i=0;i<n;i++) 
	{
		cin>>a[i];
		dpX[i][i] = a[i];
		dpY[i][i] = -a[i];
	}

	for(int l=2;l<=n;l++)
	{
		for(int i=0;i+l<=n;i++)
		{
			int j= i+l-1;
			if(j<n)
			{
				dpX[i][j] = max(dpY[i][j-1]+a[j] , a[i]+ dpY[i+1][j]);
				dpY[i][j] = min(dpX[i][j-1]-a[j],dpX[i+1][j]-a[i]);
			}
		}
	}

	cout<<dpX[0][n-1]<<endl;
}