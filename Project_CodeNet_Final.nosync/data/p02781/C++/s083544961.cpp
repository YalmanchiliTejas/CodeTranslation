#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
#define eps 1e-6
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
ll dp[110][4][2];
bool vis[110][4][2];
string s;
int k,n;
inline ll solve(int dig,int cnt,int sma)
{
//	cout<<dig<<" "<<cnt<<" "<<sma<<endl;
	if(cnt>k)return 0;
	if(vis[dig][cnt][sma])return dp[dig][cnt][sma];
	vis[dig][cnt][sma]=1;
	dp[dig][cnt][sma]=0;
	if(dig==n)
	{
		return dp[dig][cnt][sma]=(cnt==k);
	}
	if(sma)
	{
		dp[dig][cnt][sma]+=solve(dig+1,cnt,1)+9ll*solve(dig+1,cnt+1,1);
	}
	else
	{
		dp[dig][cnt][sma]+=solve(dig+1,cnt,s[dig]>'0');
		for(char c='1';c<s[dig];c++)
			dp[dig][cnt][sma]+=solve(dig+1,cnt+1,1);
		if(s[dig]!='0')dp[dig][cnt][sma]+=solve(dig+1,cnt+1,0);
	}
//	cout<<dp[dig][cnt][sma]<<endl;
	return dp[dig][cnt][sma];
}
int main()
{
	cin>>s>>k;
	n=s.length();
	cout<<(ll)solve(0,0,0)<<endl;
	return 0;
}