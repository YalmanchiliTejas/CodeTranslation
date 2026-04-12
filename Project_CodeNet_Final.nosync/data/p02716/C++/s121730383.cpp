#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> in(n);
    FOR(i,0,n)cin>>in[i];

    vector<ll> dp1(n/2,-1e17);
    vector<ll> dp2(n/2,-1e17);
    vector<ll> dp3(n/2,-1e17);
    dp1[0] = in[0];
    FOR(i,2,n){
        if(i+1>=n)break;
    //    cout<<"i1 = "<<i<<endl;
        dp1[i/2] = dp1[i/2-1] + in[i];
        i++;
    }
    dp2[0] = in[1];
    FOR(i,2,n){
        if(i+1>=n)break;
    //    cout<<"i2 = "<<i<<endl;
        dp2[i/2] = max(dp1[i/2-1],dp2[i/2-1]) + in[i+1];
        i++;
    }
    if(n>2)dp3[0] = in[2];
    FOR(i,2,n){
        if(i+2>=n)break;
    //    cout<<"i3 = "<<i<<endl;
        dp3[i/2] = max(dp1[i/2-1],max(dp2[i/2-1],dp3[i/2-1])) + in[i+2];
        i++;
    }

    ll ans = max(dp1[n/2-1],max(dp2[n/2-1],dp3[n/2-1]));
    cout<<ans<<endl;
    
    
}