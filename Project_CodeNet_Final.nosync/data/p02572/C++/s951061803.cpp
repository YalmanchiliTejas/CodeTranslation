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
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll a[N];
ll b[N];
ll ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        b[i]=x;
        a[i]=a[i-1]+x;
    }
    for(int i=1;i<=n;i++)
    {
        ans=(ans+(b[i]*(a[i-1]%mod)%mod))%mod;
    }
    cout<<ans<<endl;
    return 0;
}
