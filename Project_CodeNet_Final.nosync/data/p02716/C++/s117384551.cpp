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
#define mod 998244353
#define N 200010
using namespace std;
int a[N];
ll dp[N];
ll pre[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    pre[1]=a[1];
    for(int i=3;i<=n;i++)
    {
        pre[i]=pre[i-2]+a[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(i&1)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }
        else
        {
            dp[i] = max(pre[i - 1], dp[i - 2] + a[i]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
