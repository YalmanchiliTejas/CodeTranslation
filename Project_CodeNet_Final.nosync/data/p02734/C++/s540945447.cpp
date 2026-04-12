/* ****revpro**** */
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define endl     '\n'
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll)x.size()
#define hell        998244353
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--)    
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define mii      map<ll,ll>
using namespace std;

#define TIME        cerr << "\nTime elapsed: " << setprecision(5) <<1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N  100005
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;  
#define ordered_set tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update>
ll add(ll x,ll y,ll mod=hell) { x += y; if(x >= mod) x -= mod; return x;}
 ll sub(ll x,ll y,ll mod=hell) { x -= y; if(x < 0) x += mod; return x;}
 ll mul(ll x,ll y,ll mod=hell) { return (x * 1ll * y) % mod;} 
ll dp[3005][3005];
void solve()
{
  ll n,s;
  cin>>n>>s;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  ll ans=0;
  rep(i,0,n)
  {
    dp[i+1][a[i]]=add(0LL,i+1);
    rep(j,1,3005) {
      if(j+a[i]<3005)
        dp[i+1][j+a[i]]=add(dp[i+1][j+a[i]],dp[i][j]);
      dp[i+1][j]=add(dp[i+1][j],dp[i][j]);
    }
    ans=add(ans,dp[i+1][s]);
  }
  // rep(i,1,n+1)
  // {
  //   rep(j,1,s+1) cout<<dp[i][j]<<' ';
  //   cout<<endl;
  // }
  cout<<ans;
}
signed main()
{
  
    /***********************************/
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937_64 generator (seed);
    /***********************************/
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS=1;
//  cin>>TESTS;
  while(TESTS--)
  {
    solve();
    
  }
  TIME
  return 0;
}