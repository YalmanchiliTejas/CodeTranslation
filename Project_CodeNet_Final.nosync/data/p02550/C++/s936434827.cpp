#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int mod = 998244353;
const ll INF = -(ll)1e10;

int main()
{
    ll n, x, m;
    cin>>n>>x>>m;
    vll pfx_sum(m);
    vll rem(m);
    pfx_sum[1]=x;
    rem[x]=1;
    ll prev = x;
    ll ans = 0;
    for(int i = 2; i<=min(n, m+1); i++)
    {
        prev = (prev*prev)%m;
        if(prev==0)
        {
            cout<<pfx_sum[i-1]<<endl;
            return(0);
        }
        if(rem[prev])
        {
            ans = pfx_sum[i-1];
            ll left = n-i+1;
            ll div = left/(i-rem[prev]);
            ll remainder = left%(i-rem[prev]);
            ans+=((pfx_sum[i-1]-pfx_sum[rem[prev]-1])*div);
            ans+=(pfx_sum[rem[prev]+remainder-1]-pfx_sum[rem[prev]-1]);
            cout<<ans<<endl;
            return(0);
        }
        else
        {
            rem[prev]=i;
            pfx_sum[i]=(pfx_sum[i-1]+prev);
        }        
    }
    cout<<pfx_sum[n]<<endl;
}