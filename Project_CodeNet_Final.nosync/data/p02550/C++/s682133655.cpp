#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define INF 4e18
using namespace std;
 
typedef tree<ll, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    ordered_set; 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset;

ll prck(ll n)
{
    ll f=1;
    if(n==1)
        f=0;
    else if(n==2)
        f=1;
    else if(n%2==0)
        f=0;
    else
    {
        ll i;
        for(i=3;(i*i<=n) && (f==1);i+=2)
        {
            if(n%i==0)
                f=0;
        }
    }
    return f;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    /*ll t,tcitr;
    cin>>t;
    tcitr=0;
    while(tcitr<t)
    {*/
        ll n,i,j,x,m;
        cin>>n>>x>>m;
        vector<ll> sm;
        map<ll,ll> mp;
        bool printed=false;
        sm.push_back(0LL);
        for(i=1;i<=n;i++)
        {
            sm.push_back(x);
            
            if(i)sm[i]+=sm[i-1];
            if(mp.count(x))
            {
                ll repeat=mp[x];
                //0  to repeat-1
                ll ans=sm[repeat-1];

                ll pattern=sm[i-1]-sm[repeat-1];

                ll block=i-1-repeat+1;

                ans+=((n-repeat+1)/block)*pattern;
                ll rem=(n-repeat+1)%block;
                ans+=sm[repeat-1+rem]-sm[repeat-1];
                cout<<ans<<"\n";
                printed=true;
                break;
            }
            else
            {
                mp[x]=i;
                x=(x*x)%m;
            }
        }
        if(!printed)cout<<sm[n]<<"\n";
        /*tcitr++;
    }*/
    return 0;
}