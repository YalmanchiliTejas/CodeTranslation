// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 100005
#define INF (ll)1e18
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define vv vector
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define repr(i,n) repr2(i,n,0)
#define repr2(i,m,n) for(ll i=m;i>=(n);i--)
#define get(n) ll (n); scanf("%lld",&(n));
#define get2(n,k) ll (n),(k); scanf("%lld%lld",&(n),&(k));
#define get3(n,m,k) ll (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k));
#define gets(s) string (s); cin >> (s);
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) vector<ll> A((n)); for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); //cout.tie(0);
#define pi 3.1415926535897
#define db long double  /* print with %Lf */
#define EPS 1e-9
#define flu fflush(stdout)
#define imp {cout<<"0\n"; return 0;}
#define yup {cout<<"YES\n"; return 0;}
#define debug_vec(vec,n) {rep(idxi,n) cout<<vec[idxi]<<" "; cout<<"\n";}
#define debug_pvec(vec,n) {rep(idxi,n) cout<<vec[idxi].fi<<"-"<<vec[idxi].se<<"  "; cout<<"\n";}
#define debug_set(seta) {cout<<seta.size()<<"\n"; for(auto idxi:seta) cout<<idxi<<" "; cout<<"\n";}
#define debug_map(mappa) {cout<<mappa.size()<<"\n";for(auto idxi:mappa) cout<<idxi.fi<<"-"<<idxi.se<<"  "; cout<<"\n";}
#define debug_vecvec(vec,n) {rep(idxi,n) {for(auto idxi2:vec[idxi]) cout<<idxi2<<" "; cout<<"\n";}}
 
// LOOK AT THESE BEFORE SUBMISSION
// LOOK AT THESE BEFORE SUBMISSION
// ============================================================
// Nmax value and is index access offset taking it beyond Nmax.
// Precision error in case of real numbers.
// N vs N2 chosen correctly.
// Modulo applied everywhere.
// Flush in case of interactive.
// Don't erase value in multiset.
// Check for array indices out of bound (in pre or suff sums).
// Correct return value for functions.
// Confirm the letter case of yes and no.
// Dont paste code two times in the text file.
// ============================================================

int main() {
    
    string s;
    cin >> s;

    get(d);

    vector<vector<ll>> dp(d+1, vector<ll>(2,0));
    dp[0][1] = 1;

    for(ll i=0;i<s.length();i++) {
        vector<vector<ll>> dp2(d+1, vector<ll>(2,0));
        for(ll j=0;j<=9;j++) {
            for(ll k=0;k<=d;k++) {
                if(j==0) dp2[k][0] += dp[k][0];
                else if(k+1<=d) dp2[k+1][0] += dp[k][0];
            }
        }

        ll digi = s[i]-'0';
        for(ll j=0;j<digi;j++) {
            for(ll k=0;k<=d;k++) {
                if(j==0) dp2[k][0] += dp[k][1];
                else if(k+1<=d) dp2[k+1][0] += dp[k][1];
            }
        }

        for(ll k=0;k<=d;k++) {
            if(digi==0) dp2[k][1] += dp[k][1];
            else if(k+1<=d) dp2[k+1][1] += dp[k][1];
        }

        dp = dp2;
    }

    ll ans = (dp[d][1]+dp[d][0]);

    printf("%lld\n", ans);
    return 0;  
}