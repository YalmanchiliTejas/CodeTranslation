
/*
				GAURAV KUMAR
				 MNNIT
				  BTECH 3RD YEAR
*/

#include<bits/stdc++.h>
using namespace std;
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;
typedef long long int ll;
const ll INF=1e12;
ll dp[3001][3001][2];
ll dp1[3001][3001][2];
ll a[3001];
ll fun(int i,int j,int t)
{
	if(i==j)
	{
		if(t==0)return a[i];
		return -a[i];
	}
	ll ans;
	if(dp1[i][j][t]!=0)return dp[i][j][t];
	if(t==0)
	{
		ans=fun(i+1,j,1-t)+a[i];
		ans=max(ans,fun(i,j-1,1-t)+a[j]);
	}
	else
	{
		ans=fun(i+1,j,1-t)-a[i];
		ans=min(ans,fun(i,j-1,1-t)-a[j]);
	}
	dp1[i][j][t]=1;
	return dp[i][j][t]=ans;



}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<fun(0,n-1,0)<<endl;
}