/******************************************
* AUTHOR : Lokesh goel*
* NICK : InsaneNerd *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000000
#define N 100005
#define pii pair<int,int>
#define vp vector<pair<int,int > >
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define gsz(x) ((int)(x).size())
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cerr.tie(NULL);
#define endl "\n"
#define ms(x,v) memset(x,v,sizeof(x))

ll solve(ll dp[][4],ll n,ll a[],ll i,ll left,ll count)
{
	if(i>=n)
	{
		if(count==n/2)
		{
			return 0;
		}
		else return -MAX;
	}
	if(dp[i][left]!=-1)
	{
		return dp[i][left];
	}
	if(left==0)
	{
		dp[i][left] = solve(dp,n,a,i+2,left,count+1)+a[i];
	}
	else if(left==1)
	{
		dp[i][left] = max(solve(dp,n,a,i+2,left,count+1)+a[i],solve(dp,n,a,i+1,left-1,count));
	}
	else if(left==2)
	{
		dp[i][left] = max(solve(dp,n,a,i+2,left,count+1)+a[i],max(solve(dp,n,a,i+1,left-1,count),solve(dp,n,a,i+2,left-2,count)));
	}
	else
	{
		//if(i!=0&&i!=n-3)
			dp[i][left] = max(solve(dp,n,a,i+2,left,count+1)+a[i],max(solve(dp,n,a,i+1,left-1,count),max(solve(dp,n,a,i+2,left-2,count),solve(dp,n,a,i+3,left-3,count))));

	}
	return dp[i][left];
}

int main()
{
	fastio;
	ll n,i,j,k,a[200001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	// if(n%2==0)
	// {
	// 	ll sum1 = 0,sum2=0;
	// 	for(i=0;i<n;i+=2)
	// 	{
	// 		sum1+=a[i];
	// 	}
	// 	for(i=1;i<n;i+=2)
	// 	{
	// 		sum2+=a[i];
	// 	}
	// 	cout<<max(sum1,sum2)<<endl;
	// }
	
	{
		
		ll dp[n+1][4];
		ms(dp,-1);
		cout<<solve(dp,n,a,0,3,0)<<endl;

	}


	return 0;
}