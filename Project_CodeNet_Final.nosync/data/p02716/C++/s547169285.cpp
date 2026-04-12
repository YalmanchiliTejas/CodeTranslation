
#include <bits/stdc++.h>
using namespace std;


#define M 1000000007
#define pb push_back
#define mp make_pair
#define s second
#define f first
#define mod 998244353
#define sz(v) (int)(v).size()

#define pii pair<int, int>
#define vi vector<int>
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)

ll add(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a+b)%M;
	return (p+M)%M;
}

ll mul(ll a,ll b)
{
	a%=M;
	b%=M;
	ll p = (a*b)%M;
	return (p+M)%M;
}

ll dp[200010][4]={0};

int main()
{
	fastio;
	ll i,n,a[200010];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	ll sum=0,ma=-1e15;
	// if(	n%2==0)
	// {
	// 	ll pre[200010]={0},suf[200010]={0};
	// 	for(i=0;i<n;i+=2)
	// 		sum+=a[i];
	// 	ma=max(ma,sum);
	// 	sum=0;
	// 	for(i=1;i<n;i+=2)
	// 		sum+=a[i];
	// 	ma=max(ma,sum);
	// 	pre[0]=a[0];
	// 	pre[1]=a[1];
	// 	for(i=1;i<n;i++)
	// 		pre[i]=pre[i-2]+a[i];
	// 	for(i=n-1;i>=0;i--)
	// 		suf[i]=suf[i+2]+a[i];
	// 	for(i=0;i<n;i++)
	// 		ma=max(ma,pre[i]+suf[i+3]);
	// 	cout<<ma<<endl;
	// }
	// else
	// {
	ma=-1e15;
	for(i=0;i<=n;i++)
		dp[i][0]=dp[i][1]=dp[i][2]=-1e15;
	dp[1][0]=a[0];
	dp[2][1]=a[1];
	dp[3][0]=a[0]+a[2];
	dp[3][2]=a[2];
	for(i=4;i<=n;i++)
	{
		dp[i][2]=max(dp[i-2][2],max(dp[i-3][1],dp[i-4][0]))+a[i-1];
		dp[i][1]=max(dp[i-2][1],dp[i-3][0])+a[i-1];
		dp[i][0]=dp[i-2][0]+a[i-1];
	}
	if(n&1)
		ma=max(dp[n][2],max(dp[n-1][1],dp[n-2][0]));
	else
		ma=max(dp[n][1],dp[n-1][0]);
	cout<<ma<<endl;
	// }
    return 0;
}



