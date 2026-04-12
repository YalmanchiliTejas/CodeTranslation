
// Problem : E - Almost Everywhere Zero
// Contest : AtCoder - AtCoder Beginner Contest 154
// URL : https://atcoder.jp/contests/abc154/tasks/abc154_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//mst,pq,mp,st,q
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(x) begin(x),end(x)

int mod = 1e9+7;
int inf = 4e18;
const int N = 5e5+5;
int k;
string n;
int ns;
int arr[105];
int dp[105][5][2];
void help(string &s)
{
	ns = s.size();
	for(int i =0;i<ns;++i)
	arr[i+1] = (s[i]-'0');
}
int help1(int pos,int cnt,int flag)
{
	if(cnt>k)
	return 0;
	if(pos==ns+1)
	{
		return cnt==k;
	}
	int &ans = dp[pos][cnt][flag];
	if(ans!=-1)
	return ans;
	ans = 0;
	if(!flag)
	{
		for(int i=0;i<=arr[pos];++i)
		{
			if(i!=0)
			ans+= help1(pos+1,cnt+1,flag|(i<arr[pos]));
			else
			ans+=help1(pos+1,cnt,flag|(i<arr[pos]));
			if(ans>=mod)
			ans-=mod;
		}
	}
	else
	{
		for(int i=0;i<=9;++i)
		{
			if(i!=0)
			ans+= help1(pos+1,cnt+1,flag);
			else
			ans+=help1(pos+1,cnt,flag);
			if(ans>=mod)
			ans-=mod;
		}
	}
	return ans;
}
signed main()
{
    io
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
    	cin>>n>>k;
    	help(n);
    	memset(dp,-1,sizeof(dp));
    	int ans = help1(1,0,0);
    	cout<<ans;
    }
    return 0;
}
