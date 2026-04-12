/*
ABHIJEET BISWAS
CSE (2017-2021)
MNNIT ALLAHBAD
*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e15
#define ll long long
#define ld long double
#define int ll
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define MAX 1000009
#define pb push_back
#define mp map<int,int>
#define F first
#define S second
#define popi __builtin_popcount
#define popll __builtin_popcountll
#define grp vector<int> graph[MAX];
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//////////////////////TEMPLATE ENDS///////////////////////////////////////////////////////////////////////
ll power(ll,ll);
ll mpower(ll,ll);
//////////////////////////////////////////////////////////////////////////////////////////////////////////


int32_t main() {
	fastIO


	int d;
	string in;
	cin>>in>>d;
	
	int n = in.size();
	int dp[n+1][d][2];
	memset(dp,0,sizeof dp);
	dp[n][0][0]=dp[n][0][1] =1;
	for(int id=n-1;id>=0;id--)
	{
		for(int j=0;j<d;j++)
		{
			for(int m=0;m<2;m++)
			{
				//cout<<((m==1)?(in[id]-'0'):9)<<" "<<id<<endl;
				for(int k=0;k<=((m==1)?(in[id]-'0'):9);k++)
				{
					
					dp[id][j][m]=(dp[id][j][m]+dp[id+1][(j+k)%d][m==1 and k==(in[id]-'0')])%MOD;
				}
			}
		}
	}

	
	int ans =( dp[0][0][1]-1+MOD)%MOD;
	cout<<ans<<endl;
	
	
	return 0;
}







/*_________________________________________________Utility Functions HERE_______________________________*/

ll power(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b%2==1)
		res=res*a;
		a=a*a;
		b=b/2;
	}
	return res;
}
ll mpower(ll a ,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b%2==1)
		{
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return res;
}