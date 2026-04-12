#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define Endl endl
#define mod  1000000007
#define mkp make_pair
#define pb push_back
#define cin(n) scanf("%d",&n)
#define cout(n) printf("%d ",n)
#define sf(n) scanf("%d",&n)
#define pf(n) printf("%d ",n)
#define bitget(n) __builtin_popcountll(n)
#define maxi 500111

ll dx[] = {1,1,0,-1,-1,-1,0,1};
ll dy[] = {0,-1,-1,-1,0,1,1,1};
ll dxx[] = {1,-1,0,0};
ll dyy[] = {0,0,-1,1};
ll modexpo(ll x,ll y){if(y==0)return 1;if(y%2){ll viky=modexpo(x,y/2);
return (((x*viky)%mod)*viky)%mod;}else{ll viky=modexpo(x,y/2);return (viky*viky)%mod;
}}
ll intpoint(ll x1, ll y1, ll x2, ll y2) { return ( __gcd(abs(x1-x2),abs(y1-y2))+1); }
bool isvalid(ll x,ll y,ll n,ll m) { return (x>=0&&x<n&&y>=0&&y<m); }
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pp = uniform_int_distribution<int>(0, kk-1)(rng);
// ---------------------///////////////---------------------------------
// ---------------------///////////////----------------------------------
// -------------/////////////////---------------------------------///////

struct gg{
  ll first;
  ll second;
};

gg dp[3011][3011];


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    cin>>n;

    ll ap[n+11];

    for(ll i=0;i<n;i++){
      cin>>ap[i];
    }

    for(ll i=0;i<n;i++){
      dp[i][i].first = ap[i];
      dp[i][i].second = 0;
    }

    for(ll i=1;i<n;i++){
      for(ll j = i-1;j>=0;j--){
        ll sum = dp[j][i-1].first + dp[j][i-1].second + ap[i];
        dp[j][i].first = max(dp[j][i-1].second + ap[i],dp[j+1][i].second + ap[j]);
        dp[j][i].second = sum - dp[j][i].first;
      }
    }

    for(ll i=0;i<n;i++){
      for(ll j=0;j<n;j++){
        // cout<<dp[i][j].first<<" "<<dp[i][j].second<<" ";
      }
      // cout<<"\n";
    }

    cout<<(dp[0][n-1].first-dp[0][n-1].second);

    return 0;
}