#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 998244353
#define PI 3.14159265358979323846
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    //int c=0;
    while(t--) {

       ll n,x,m,i,j;
       cin>>n>>x>>m;
       vector<ll> dp;
       dp.pb(0);
       dp.pb(x);
       map<ll,ll> mp;
       mp[x]=1;
       for(i=1;i<min(n,m+5);i++)
       {
           x=(x*x)%m;
           if(x==0)
            break;
           if(mp[x])
            break;
           mp[x]=i+1;
           dp.pb(x);
       }
       if(!x || i==n)
       {
           ll ans=0;
           for(i=0;i<dp.size();i++)
            ans+=dp[i];
           cout<<ans;
           return 0;
       }

       ll c;
       ll pos=mp[x];
       n=n-(pos-1);
       vector<ll> v2;
       for(i=pos;i<dp.size();i++)
        v2.pb(dp[i]);
       ll ans=0;
       for(i=0;i<pos;i++)
        ans+=dp[i];
       c=v2.size();
       for(i=1;i<v2.size();i++)
        v2[i]+=v2[i-1];
        ll r=n/c;
        ans+=v2[c-1]*r;
        r=n%c;
        if(r)
        ans+=v2[r-1];

       cout<<ans;
    }

}
