// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 100001
#define INF (ll)1e18
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define get(n) ll (n); scanf("%lld",&(n));
#define get2(n,k) ll (n),(k); scanf("%lld%lld",&(n),&(k));
#define get3(n,m,k) ll (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k));
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) vector<ll> A((n)); for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);
#define pi 3.1415926535897


int main() {
    
    string s;
    cin >> s;

    get(d);

    vector<vector<ll>> dp(d, vector<ll>(2,0));
    dp[0][1] = 1;

    for(ll i=0;i<s.length();i++) {
        vector<vector<ll>> dp2(d, vector<ll>(2,0));
        for(ll j=0;j<=9;j++) {
            for(ll k=0;k<d;k++)
                dp2[(k+j)%d][0] = (dp2[(k+j)%d][0] + dp[k][0])%N; 
        }

        ll digi = s[i]-'0';
        for(ll j=0;j<digi;j++) {
            for(ll k=0;k<d;k++)
                dp2[(k+j)%d][0] = (dp[k][1] + dp2[(k+j)%d][0])%N;
        }

        for(ll k=0;k<d;k++)
            dp2[(k+digi)%d][1] = (dp2[(k+digi)%d][1] + dp[k][1])%N;

        dp = dp2;
    }

    ll ans = (dp[0][1]+dp[0][0]-1)%N;

    printf("%lld\n",(N+ans)%N);
    return 0;  
}