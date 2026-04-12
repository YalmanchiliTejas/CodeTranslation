#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;;
#define ato find_by_order
#define of order_of_key
typedef long long ll;
#define mp make_pair
#define pb push_back
#define flash ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
int main()
{
    flash
    ll n;ll x;ll m;
    cin>>n>>x>>m;ll cnt=n-1;ll sum=x;
    if(x%m==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    map<ll,ll> maxu;map<ll,ll> s;s[0]=0;s[1]=x;ll dix=0;ll ins=0;
    for(ll i=1;i<=n-1;i++)
    {
        x=(x*x)%m;
        if(maxu.find(x)!=maxu.end())
        {
            ins=s[i]-s[maxu[x]-1];
            dix=(i+1)-(maxu[x])+1;
            break;
        }
        maxu[x]=i+1;
        cnt--;
       sum=(sum+x);
       s[i+1]=sum;
    }
    ll yo=cnt/(dix-1);yo=yo*ins;
    yo+=(s[maxu[x]-1+cnt%(dix-1)]-s[maxu[x]-1]);
    cout<<yo+sum<<endl;
}