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
#define N 10004
#define D 104
#define INF 1e9+7

using namespace std;

string k;
ll d,n,mod=1e9+7;
ll dp[N][D][2];

ll solve(ll digit,ll sum,ll smaller)
{
    if(digit == n)
        return (sum == 0) ? 1 : 0;

    if(dp[digit][sum][smaller] != -1)
        return dp[digit][sum][smaller];

    ll res = 0;

    rep(c,0,10)
    {
        if(c == k[digit]-'0')
            res = (res+solve(digit+1,(sum+c)%d,smaller))%mod;
        else if(!smaller && c > k[digit]-'0')
            continue;
        else
            res = (res+solve(digit+1,(sum+c)%d,1))%mod;
    }

 //   cout << digit << " " << sum << " "<< smaller << "   " << res << endl;

    return dp[digit][sum][smaller] = res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(dp,-1,sizeof dp);

    cin >> k >> d;
    n=k.size();

    cout << (solve(0,0,0)+mod-1)%mod;

    return 0;
}

