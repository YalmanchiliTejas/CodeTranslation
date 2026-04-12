//From Naruto to Hokage
//#include <RJ>
#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define pb          push_back
#define eb          emplace_back
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
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
const int N=3005;
vi v;
ll dp[N][N];
ll rec(ll l,ll r){
    ll &ans=dp[l][r];
    if(ans!=-1) return ans;
    if(l==r) return ans=v[l];
    return ans=max(v[l]-rec(l+1,r),v[r]-rec(l,r-1));
}
void solve(){
    ll n,x;
    cin>>n;
    rep(i,0,n-1) cin>>x,v.push_back(x);
    rep(i,0,N-1) rep(j,0,N-1) dp[i][j]=-1;
    // memset(dp,0,sizeof(dp));
    cout<<rec(0,n-1);
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