#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define ll long long
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=998244353;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
  ll n,s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<vector<ll>> d(n+1,vector<ll>(5000,0));
  rep(i,n){
    d[i][0]=i+1;
  }
  ll ans=0;
  rep(i,n){
    rep(j,s){
      if (j!=0) d[i+1][j]=(d[i+1][j]+d[i][j])%MOD;
      if (j+a[i]==s){
        ans=(ans+d[i][j]*(n-i))%MOD;
      }
      if (j+a[i]<s){
        d[i+1][j+a[i]]=(d[i+1][j+a[i]]+d[i][j])%MOD;
      }
    }
  }
  cout << ans << endl;
}
