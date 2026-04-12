#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define md 1000000007
#define mx 1e18
#define pb push_back
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<ll int,ll int>
#define ff first
#define ss second
int dp[10001][102][2];
string s;
ll int d;
ll int n;
ll int ar[10001];

ll int f(ll int i , ll int j , ll int ff)
{

	if(i==n)
	{
		if(j==0)
			return 1;
		else
			return 0;
	}

	if(dp[i][j][ff]!=-1)
		return dp[i][j][ff];

	ll int ans=0;
	if(ff)
	{
		for(ll int x=0;x<=9;x++)
		{
			ans+=f(i+1,(j-x+d)%d,1);
			ans%=md;
		}
	}
	else
	{
		for(ll int x=0;x<ar[i];x++)
		{
			ans+=f(i+1,(j-x+d)%d,1);
			ans%=md;
		}
		ans+=f(i+1,(j-ar[i]+d)%d,0);
		ans%=md;
	}
	return dp[i][j][ff] = ans;
}

int main()
{
	// fastio
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt" , "r" , stdin);
	// freopen("output.txt" , "w" , stdout);
	// #endif

	cin>>s;
	cin>>d;
	n=s.length();
	memset(dp,-1,sizeof(dp));

	for(ll int i=0;i<n;i++)
		ar[i]=s[i]-'0';

	ll int ans = f(0,0,0)-1;
	ans=(ans+md)%md;

	cout<<ans<<endl;

	return 0;
}
