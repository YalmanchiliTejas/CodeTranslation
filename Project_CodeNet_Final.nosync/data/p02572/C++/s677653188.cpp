#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
#include <fstream>
#include<string.h>
#include <algorithm>
#include<math.h>
#include<vector>
#include <queue>
#include <deque> 
#define ll long long
#define M 1000000007 
#define MM 998244353
#define INF (1LL<<60)-1
using namespace std;
 
bool isBig(ll x,ll n)
{
    ll trm=1;
    for(ll i=0;i<n-1;i++)
    {
        trm*=x;
        if(trm>1e18)return true;
    }
    return false;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*ll t,tcitr;
    cin>>t;
    tcitr=0;
    while(tcitr<t)
    {*/
        //cout<<"Case #"<<tcitr+1<<": ";
        ll n,i,j,k;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++)cin>>a[i];
        ll pre[n];
        pre[0]=a[0];
        for(i=1;i<n;i++)pre[i]=pre[i-1]+a[i];
        ll ans=0;
        for(i=0;i<n;i++)
        {
            ans=(ans+(a[i]*((pre[n-1]-pre[i])%M))%M)%M;
        }
        cout<<ans<<"\n";
        /*tcitr++;
    }*/
    return 0;
}