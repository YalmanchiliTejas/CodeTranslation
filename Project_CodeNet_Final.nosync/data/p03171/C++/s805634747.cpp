#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fr(i,j,n)   for(long long i=j;i<(n);++i)
#define bk(i,j,n)   for(long long i=j;i>=n;--i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define endl "\n"
#define MOD 1000000007
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define srt(x) sort(x.begin(),x.end());
#define ret     return 0;
#define mem(x,y)    memset((x),(y),sizeof (x));
#define run ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ordered_set tree<ll , null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;

//std::cout << std::setprecision(12) << s << '\n';
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}

ll n;
ll a[3002];
ll dp[3002][3002][2];
ll vis[3002][3002][2];
ll fun(ll lo,ll hi,ll x,ll y,ll chnc)
{
    chnc%=2;
    if(hi<lo)
    {
        return x-y;
    }
    if(hi==lo)
    {
        if(chnc)
            y+=a[hi];
        else
            x+=a[hi];
        return x-y;

    }
    if(vis[lo][hi][chnc])
        return dp[lo][hi][chnc];
    vis[lo][hi][chnc]=1;

    if(chnc%2)
    {
        ll o=fun(lo,hi-1,x,y,chnc+1)-a[hi];
        ll p=fun(lo+1,hi,x,y,chnc+1)-a[lo];

        o=min(o,p);
        dp[lo][hi][chnc]=o;
        return o;


    }
    else
    {

        ll o=fun(lo,hi-1,x,y,chnc+1)+a[hi];
        ll p=fun(lo+1,hi,x,y,chnc+1)+a[lo];

        o=max(o,p);
        dp[lo][hi][chnc]=o;
        return o;

    }




}


int main()
{
    run;
    cin>>n;
    fr(i,0,n)
    {
        cin>>a[i];
    }
    ll o=fun(0,n-1,0,0,0);
    cout<<o;





}
