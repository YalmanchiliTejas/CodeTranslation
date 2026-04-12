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
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
int a[N];
int b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n%2==1)
    {
        ll ans=0;
        for(int i=1;i<=n/2-1;i++)
        {
            ans-=2*a[i];
        }
        ans=ans-a[n/2+1]-a[n/2];
        for(int i=n/2+2;i<=n;i++)
        {
            ans+=2*a[i];
        }
        ll tem=0;
        for(int i=n/2+3;i<=n;i++)
        {
            tem+=2*a[i];
        }
        tem+=a[n/2+1]+a[n/2+2];
        for(int i=1;i<=n/2;i++)
        {
            tem-=2*a[i];
        }
        ans=max(ans,tem);
        cout<<ans<<endl;
    }
    else
    {
        ll ans=0;
        for(int i=1;i<=n/2-1;i++)
        {
            ans-=2*a[i];
        }
        ans=ans-a[n/2+1]-a[n/2];
        for(int i=n/2+1;i<=n;i++)
        {
            ans+=2*a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
