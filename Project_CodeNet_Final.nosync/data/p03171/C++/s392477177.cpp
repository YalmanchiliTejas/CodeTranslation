//mangesh2102000

#include <bits/stdc++.h>
using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int 
#define ld long double
#define pb push_back
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); ++it)
#define F first
#define S second
#define mod 1000000007

int n;
int a[3005];
int dp[3005][3005][2];

int solve1(int s,int e,int p)
{
	if(dp[s][e][p] != -1)
		return dp[s][e][p];

	if(s==e && p==0)
		return dp[s][e][p] = a[s];

	if(s==e && p==1)
		return dp[s][e][p] = 0;

	if(s > e)
		return dp[s][e][p] = 0;

	if(p==0)
		return dp[s][e][p] = max(a[s]+solve1(s+1,e,1),a[e]+solve1(s,e-1,1));
	else
		return dp[s][e][p] = min(solve1(s+1,e,0),solve1(s,e-1,0));
}

void solve(int t)
{
    cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for(int i=0;i<=n;i++)
    {
    	for(int j=0;j<=n;j++)
    	{
    		dp[i][j][0] = dp[i][j][1] = -1;
    	}
    }

    int X = solve1(1,n,0);
    int Y = sum - X;
    cout << X-Y << "\n";
}   


int32_t main()
{
    IOS;
    int t;
    t=1;
    for(int i=1;i<=t;i++)
    {
        solve(i);
    }

    return 0;
}