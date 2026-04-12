#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <math.h>
#define ll long long int
using namespace std;

ll mod = 998244353;

ll power(ll x,ll y)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

ll modInverse(ll a,ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
}

ll arr[3005];
ll dp[3005][3005];
bool vis[3005][3005];

ll solve(int m,int s,int e)
{
    if(vis[s][e])
        return dp[s][e];
    vis[s][e] = true;
    if(s==e)
    {
        dp[s][e] = arr[s];
        return arr[s];
    }
    m = (m+1)%2;
    if(m%2==1)
        dp[s][e] = max(arr[s] - solve(m,s+1,e) , arr[e] - solve(m,s,e-1));
    else
        dp[s][e] = max(arr[s] - solve(m,s+1,e) , arr[e] - solve(m,s,e-1));
    return dp[s][e];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    cout << solve(0,1,n);
}
