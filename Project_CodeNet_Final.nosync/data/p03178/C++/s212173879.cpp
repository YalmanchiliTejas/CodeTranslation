#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define MOD 1000000007
int key,dp[10005][2][102];
vector<int> res;
int digit_dp(int idx,int tight,int ds)
{
	if(idx==-1&&ds==0)
	return 1;
	if(idx==-1)
	return 0;
	if(dp[idx][tight][ds]!=-1&&tight!=1)
	return dp[idx][tight][ds];
	int total=0,k=(tight==1)?res[idx]:9;
	for(int i=0;i<=k;i++)
	{
		int nt=(res[idx]==i)?tight:0;
		total=(total+digit_dp(idx-1,nt,(ds+i)%key))%MOD;
	}
	if(!tight)
	dp[idx][tight][ds]=total%MOD;
	return total%MOD;
}
signed main()
{
	string s;
	cin>>s;
	cin>>key;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		int v=(int)(s[i]-'0');
		res.push_back(v);
	}
	reverse(res.begin(),res.end());
	memset(dp,-1,sizeof(dp));
	int x=digit_dp(len-1,1,0)-1;
	if(x<0)
	x=x+MOD;
	cout<<x<<"\n";
}