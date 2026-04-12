#include<bits/stdc++.h>
#define ii pair<int,int>
#define int long long int 	
using namespace std;
int n;
vector<int>v;
ii dp[3001][3001][2];
ii solve(int i,int j,int turn)
{
	if(dp[i][j][turn].first!=-1 and dp[i][j][turn].second!=-1 )
		return dp[i][j][turn];

	if(i==j)
	{
		if(turn==0)
		return dp[i][j][turn]={v[i],0};
		return  dp[i][j][turn]={0,v[i]};
	}

	 ii x = solve(i+1,j,turn^1);
	 ii y = solve(i,j-1,turn^1);
	 
	if(turn == 0)
	{
		if(x.second > y.second)
		{
			return dp[i][j][turn]={y.first+v[j],y.second};
		}
		else return dp[i][j][turn]={x.first+v[i],x.second};
	}

	else
	{
		if(x.first > y.first)
			return dp[i][j][turn]={y.first,y.second+v[j]};
		else return dp[i][j][turn]={x.first,x.second+v[i]};
	}
	 
}
signed main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i=0;i<3001;i++)
		for(int j=0;j<3001;j++)
			for(int k=0;k<2;k++)
				dp[i][j][k]={-1,-1};

	ii x=solve(0,n-1,0);
	cout<<x.first-x.second<<"\n";
	//cout<<dp[0][n-1][1]<<"\n";


}