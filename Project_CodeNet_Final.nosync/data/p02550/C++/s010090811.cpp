#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; 
using namespace std;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
typedef long long  ll;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
#define pb push_back

#define F first
#define S second
#define SZ(a) int((a).size())
#define ALL(a) a.begin(),a.end()
#define fr(i,x,y) for(int i=x;i<y;i++)
#define frr(i,x,y) for(int i=x-1;i>=y;i--)
#define inf 1e18+1
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll power(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;}a=a*a;b>>=1;}return ans;}
ll powerm(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;ans%=mod;}a=a*a;a%=mod;b>>=1;}return ans%mod;}
VL dx={1,0,-1,0};
VL dy={0,1,0,-1};
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();

void solve()
{
    ll n,x,m;
    cin>>n>>x>>m;
    if(x==0)
    {
        cout<<"0\n";
        return;
    }
    else if(x==1)
    {
        cout<<n<<endl;
        return;
    }
    mod=m;
    ll ct=1;
    map<ll,ll> mp,pref,pos;
    pos[x]=ct;
    pref[ct]=x;
    ct++;
    ll ans=-1;
    while(ct<=n)
    {
        ll tmp=powerm(x,2);
        if(pos.count(tmp))
        {
            ll fk=pos[tmp];
            // if(fk==1)
            // {
            //     ans=pref[fk];
            //     ll dk=ct-fk;
            //     ll rem=(n-1)%dk;
            //     ll tm=(n-1)/(dk);
            //     ans+=(pref[ct-1])*tm;
            //     if(rem>0)
            //         ans+=(pref[rem+1]-tmp);
            // }
            // else
            {
                ans=pref[fk];
                ll last=ans;
                ll dk=ct-fk;
                ll rem=(n-fk)%dk;
                ll tm=(n-fk)/(dk);
                ans+=(pref[ct-1]+tmp-last)*tm;
                if(rem>0)
                    ans+=(pref[rem+fk]-last);
            }
            //cout<<fk<<" "<<ct<<endl;
            break;
        }
        else
        {
            pos[tmp]=ct;
            pref[ct]=pref[ct-1]+tmp;
            x=tmp;
            ct++;
        }
    }
    if(ans==-1)
        ans=pref[ct-1];
    cout<<ans<<endl;
    return;
}
int main()
{
    IOS;
    ll t=1,pp;
    //cin>>t;
    pp=t;
    while(t--)
    {
        //cout<<"Case #"<<pp-t<<": ";
        solve();
    }
    return 0;
}
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
*/
/*
recursion - matrix exponential

*/
// BITMASK:
// 1)When some constrall is of the order of 15-20, think of bitmask DP.
// 2)When some constrall is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algorithm