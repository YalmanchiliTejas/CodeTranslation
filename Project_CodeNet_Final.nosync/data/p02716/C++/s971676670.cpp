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
#define hell        1000000007
#define INF         (1ll<<60)
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define rrep(i,a,b)  for(ll i=a;i>=b;i--)
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int N=200005;
ll a[N];
ll n;
map<pii,ll> dp;
ll rec(ll idx,ll left){
    if(dp.find({idx,left})!=dp.end()) return dp[{idx,left}];
    if(idx>=n){
        if(left>0) {
            dp[{idx,left}]=-INF;
            return -INF;
        }
        else{
            dp[{idx,0}]=0;
            return 0;
        }
    }
    ll rem_el=n-idx;
    if(((rem_el+1)/2)<left){
        dp[{idx,left}]=-INF;
        return -INF;
    }
    ll ans;
    ans=rec(idx+1,left);
    if(left>0) ans=max(ans,rec(idx+2,left-1)+a[idx]);
    return dp[{idx,left}]=ans;
}
void solve(){
    cin>>n;
    rep(i,0,n-1) cin>>a[i];
    rec(0,n/2);
    cout<<dp[{0,n/2}]<<endl;
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