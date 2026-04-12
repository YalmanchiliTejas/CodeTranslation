#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define ll long long
#define ld long double
#define u unsigned
#define pi 3.141592653589793238462643383279502884

using namespace std;

ll n, x[3005];
ll dp[3005][3005][3];
ll vis[3005][3005][3];

ll solve(int s, int e, bool temp)
{
    if(s>e)return 0;
    ll ans;
    if(vis[s][e][temp])return dp[s][e][temp];
    vis[s][e][temp] = 1;
    if(temp)
    {
        ans = min(solve(s, e-1, !temp)-x[e], solve(s+1, e, !temp)-x[s]);
    }
    else
    {
        ans = max(solve(s, e-1, !temp)+x[e], solve(s+1, e, !temp)+x[s]);
    }
    return dp[s][e][temp] = ans;
}

int main()
{
    cin>>n;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>x[i];
    }
    cout<<solve(0, n-1, 0);
    return 0;
}
