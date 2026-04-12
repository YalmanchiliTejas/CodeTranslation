//Patwari26
#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define endl        '\n'
#define mii         map<ll,ll>
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        998244353
#define INF         (1ll<<60)
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define rrep(i,a,b)  for(ll i=a;i>=b;i--)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int N=100005;
void solve(){
    ll n,s;
    cin>>n>>s;
    vi v(n+1);
    rep(i,1,n) cin>>v[i];
    ll dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    // dp[0][0]=1;
    rep(i,1,n){
        rep(j,0,s) dp[i][j]=dp[i-1][j];
        if(v[i]<=s) dp[i][v[i]]=(dp[i][v[i]]+i)%hell;
        rep(j,0,s){
            if((v[i]+j)<=s) dp[i][v[i]+j]=(dp[i][v[i]+j]+dp[i-1][j])%hell;
        }
    }
    ll tot=0;
    rep(i,1,n){
        tot=(tot+dp[i][s])%hell;
    }
    // rep(i,1,n) rep(j,0,s) cout<<dp[i][j]<<" \n"[j==s];
    cout<<tot<<endl;
}
signed main()
{
    ios
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--){
        solve();
    }
    time
    return 0;
}