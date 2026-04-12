#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ld long double
#define pii pair<int,int>
int const M=200+10,M2=300+10,inf=1e9+10,mod=1e9+7;
int a[M];
int dp[M][M][2],mark[M][M][2];
int pw(int x,int y)
{
	if(y==0)return 1;
	int tmp=pw(x,y/2);
	if(y%2==0)return (tmp*tmp)%mod;
	return ((tmp*tmp)%mod*x)%mod;
}
void fdp(int l,int r,bool ch)
{
	if(mark[l][r][ch])return;
	mark[l][r][ch]=1;
	int now=max(a[l-1],a[r+1]);
	now++;
	int mn=inf;
	for(int i=l;i<=r;i++)
	{
		mn=min(mn,a[i]);
	}
	int last=l;
	dp[l][r][ch]=1;
	if(ch)dp[l][r][ch]=pw(2,mn-now);
	//if(ch)cout<<now<<" "<<mn<<" "<<dp[l][r][ch]<<endl;
	int bad=2;
	//if(ch==0)cout<<l<<" "<<
	for(int i=l;i<=r;i++)
	{
		if(a[i]==mn)
		{
			if(last==i)
			{
				last=i+1;
				if(!ch)dp[l][r][ch]*=2,dp[l][r][ch]%=mod;
				continue;
			}
			if(ch)
			{
				fdp(last,i-1,1);
				dp[l][r][ch]*=dp[last][i-1][1];
				dp[l][r][ch]%=mod;
				dp[l][r][ch]*=2;
				dp[l][r][ch]%=mod;
				last=i+1;
				continue;
			}
			fdp(last,i-1,1);
			fdp(last,i-1,0);
			int tmp=dp[last][i-1][0]+(dp[last][i-1][1]*4);
			tmp*=2;
			tmp%=mod;
			dp[l][r][ch]*=tmp;
			dp[l][r][ch]%=mod;
			dp[l][r][ch]%=mod;
			bad*=dp[last][i-1][1]*2;
			last=i+1;
			//cout<<last<<endl;
		//	cout<<dp[last][i-1][1]<<endl;
			bad%=mod;
		}
	}
	if(last!=r+1)
	{
		if(ch)
		{
			fdp(last,r,1);
			dp[l][r][ch]*=(dp[last][r][1]);
			dp[l][r][ch]%=mod;
			dp[l][r][ch]*=2;
			dp[l][r][ch]%=mod;
		}
		else
		{
			fdp(last,r,0);
			fdp(last,r,1);
			bad*=dp[last][r][1]*2;
			bad%=mod;
			int tmp=dp[last][r][0]+dp[last][r][1]*4;
			tmp%=mod;
			dp[l][r][ch]*=tmp;
			dp[l][r][ch]%=mod;
		}
	}
//	if(!ch)cout<<l<<" "<<r<<" "<<dp[l][r][ch]<<" "<<bad<<endl;
	if(ch==0)
	{
		dp[l][r][ch]-=bad;
		dp[l][r][ch]+=mod;
		dp[l][r][ch]%=mod;
	}
}
int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	fdp(1,n,0);
	fdp(1,n,1);
	//cout<<dp[1][n][1]<<endl;
	cout<<(dp[1][n][1]*2+dp[1][n][0])%mod;
}	