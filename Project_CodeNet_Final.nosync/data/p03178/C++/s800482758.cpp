#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define modulo 1000000007
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
string s;
ll d,n;
ll dp[100002][101][2];
ll solve(int ind, int sum, int flag){
	if(ind>=n){
		if(!sum)
			return 1;
		return 0;
	}
	if(dp[ind][sum][flag]!=-1)
		return dp[ind][sum][flag];
	int limit=9;
	if(!flag)
		limit=(s[ind]-'0');
	ll res=0;
	for (int i = 0; i <= limit; ++i){
		if(!flag && i==limit)
			res=(res+solve(ind+1,(sum+i)%d,0))%modulo;
		else
			res=(res+solve(ind+1,(sum+i)%d,1))%modulo;
	}
	dp[ind][sum][flag]=res;
	return dp[ind][sum][flag];
}
int main(){
	fast_io;
	cin>>s>>d;
	n=s.length();
	memset(dp,-1,sizeof(dp));
	ll ans=(solve(0,0,0)-1+modulo)%modulo;
	cout<<ans<<"\n";
	return 0;
}