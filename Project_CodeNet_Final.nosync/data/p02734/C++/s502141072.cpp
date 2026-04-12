//#define _GLIBCXX_DEBUG
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
#define v1out(v) FOR(i,0,v.size()){cout<<v[i]; if(i!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

ll MOD = 998244353;
int main(){
    int n, k;
    cin >> n >> k;
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    FOR(i,0,n+1)dp[i][0]=1;
    FOR(i,0,n){
        int in;
        cin>>in;
        FOR(j,0,k+1){
            (dp[i+1][j] += dp[i][j]) %= MOD;
            if(j+in<=k) ((dp[i+1][j+in]) += dp[i][j]) %= MOD;
        }
    }
    ll ans = 0;
    FOR(i,0,n+1)(ans += dp[i][k]) %= MOD;
    cout<<ans<<endl;

}