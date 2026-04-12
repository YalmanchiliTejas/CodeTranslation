#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MD=1e9+7;
string s;
int l,d;
ll dp[12345][2][102];
ll fun(int i,int st,int su)
{
	if(dp[i][st][su]!=-1) return dp[i][st][su];
	if(i==l)
	{
		if(su==0) return 1;
		else return 0;
	}
	ll ans=0;
	for(int j=0;j<10;j++)
	{
		if(!st)
		{
			if(j<s[i]-'0')
			ans=(ans+fun(i+1,1,(su+j)%d))%MD;
			else if(j==s[i]-'0')
			ans=(ans+fun(i+1,0,(su+j)%d))%MD;
		}
		else
		ans=(ans+fun(i+1,1,(su+j)%d))%MD;
	}
	return dp[i][st][su]=ans;
}
int main()
{
	cin>>s>>d;
	l=s.length();
	memset(dp,-1,sizeof(dp));
	cout<<(fun(0,0,0)-1+MD)%MD;
	return 0;
}