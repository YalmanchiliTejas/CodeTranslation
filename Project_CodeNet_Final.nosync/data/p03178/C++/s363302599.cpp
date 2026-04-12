#include<bits/stdc++.h>
#define ll 		long long
#define pb 		push_back
#define hell	1000000007
#define all(x) 	x.begin(),x.end()

using namespace std;

vector<int> R;
ll int d;
ll int dp[10005][2][105];

ll int solve(ll int len,ll int isequal,ll int make)
{
	if(len==-1)
	{
		return make==0;
	}
	ll int ret=0;
	if(dp[len][isequal][make]!=-1) return dp[len][isequal][make];
	if(isequal==0)
	{
		for(int i=0;i<=9;i++)
		{
			ret=(ret+solve(len-1,0,(make-i+100*d)%d))%hell;
		}
	}
	else
	{
		for(int i=0;i<=R[len];i++)
		{
			if(i<R[len]) ret=(ret+solve(len-1,0,(make-i+100*d)%d))%hell;
			else ret=(ret+solve(len-1,1,(make-i+100*d)%d))%hell;
		}
	}
	return dp[len][isequal][make]=ret%hell;
}

int main()
{
	string s;
	cin>>s;
	reverse(all(s));
	cin>>d;
	for(int i=0;i<s.length();i++) R.pb(s[i]-'0');
	memset(dp,-1,sizeof(dp));
	cout<<(solve(R.size()-1,1,0)+hell-1)%hell;
	return 0;
}