#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define pi pair < ll,ll >
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i = a;i < b;i++)
#define N 3004
#define INF 1e9+7

using namespace std;

ll n,k,ar[N];
ll dp[N][N][2];
bool vis[N][N][2];

ll solve(ll i,ll j,ll who)
{
    if(i > j)
        return 0;
    if(vis[i][j][who])
        return dp[i][j][who];

    vis[i][j][who] = true;

    ll res;

    if(who==0)
        res = max(solve(i+1,j,1)+ar[i],solve(i,j-1,1)+ar[j]);
    else
        res = min(solve(i+1,j,0)-ar[i],solve(i,j-1,0)-ar[j]);

    return dp[i][j][who]=res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    rep(i,0,n)
    {
        cin >> ar[i];
    }

    cout << solve(0,n-1,0);

    return 0;
}

