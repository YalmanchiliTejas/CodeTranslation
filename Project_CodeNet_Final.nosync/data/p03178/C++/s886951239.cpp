#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int MXN=10000,MXM=100;
const int MOD=1e9+7;
int dp[MXN][MXM][2];
string s;
int n,m;

int solve(int i,int r,int f){
	if(i>=n){
		return r==0;
	}
	if(dp[i][r][f]!=-1)return dp[i][r][f];
	dp[i][r][f]=0;
	if(f==0)
	{
		for(int d=0;d<10;d++)
		{
			dp[i][r][f]+=solve(i+1,(r+d)%m,f);
			dp[i][r][f]%=MOD;
		}
	}
	else
	{
		for(int d=0;d<(s[i]-'0');d++)
		{
			dp[i][r][f]+=solve(i+1,(r+d)%m,0);
			dp[i][r][f]%=MOD;
		}
		dp[i][r][f]+=solve(i+1,(r+(s[i]-'0'))%m,f);
		dp[i][r][f]%=MOD;
	}
	return dp[i][r][f];
}

int32_t main()
{
   IOS
   memset(dp,-1,sizeof(dp));
   cin>>s>>m;
   n=s.length();
   cout << (solve(0,0,1)-1+MOD)%MOD << endl;
}
