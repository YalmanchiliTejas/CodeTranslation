
 
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=a;i>b;i--)
#define mkp(a,b) make_pair(a,b)
#define all(v) v.begin(),v.end()
#define max3(a,b,c) max(a,(max(b,c))
#define min3(a,b,c) min(a,(min(b,c))
#define read(a) cin>>a
#define readt(a,b) read(a),read(b)
#define mod 1000000007
using namespace std;
bool compare(pair<int,int>& p1,pair<int,int>& p2)
{
    return p1.second<p2.second;
}
int main()
{
    fastio
    ll n;
    read(n);
    vector<ll> v(n),sum(n);
    
    ll cs=0;
    rep(i,0,n)
    {
        cin>>v[i];
    }
    repv(i,n-1,-1)
    {
        cs=(cs+v[i])%mod;
        sum[i]=cs;
    }
    ll ans=0;
    rep(i,0,n-1)
    {
        ll ft=v[i],st=sum[i+1];
        ans=(ans%mod+((ft)%mod*(st)%mod)%mod)%mod;
    }
    cout<<ans<<"\n";
    
}