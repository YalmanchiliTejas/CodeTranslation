#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f3f3f3f3f
#define pi 3.1415926535898
#define N 200010
using namespace std;
const int mod=998244353;
int dp[3030][3030];
int a[N];
ll ans;
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            dp[i][j]=dp[i-1][j];
        }
        for(int j=a[i]; j<=s; j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%mod;
        }
        dp[i][a[i]]=(dp[i][a[i]]+i)%mod;
        ans = (ans+dp[i][s])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
