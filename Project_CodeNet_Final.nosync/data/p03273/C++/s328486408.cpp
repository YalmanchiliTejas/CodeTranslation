#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vl;
typedef set<ll> sl;
typedef pair<ll, ll> PP;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, n) for(ll i = 1; i <= ll(n); i++)
//#define rep(i, k, n) for(ll i = k-1; i < ll(n); i++)
//#define rep2(i, k, n) for(ll i = k; i <= ll(n); i++)
#define all(v) v.begin(), v.end()
//bool chmin(ll & a, ll  b) { if (b < a) { a = b; return 1; } return 0; }
//bool chmax(ll & a, ll b) { if (b > a) { a = b; return 1; } return 0; }
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX_N=500010;
ll N, ans=0;
int main() {
  ll H, W;
  cin >> H >> W;
  char a[H][W];
  rep(i, H) rep(j, W) cin >> a[i][j];
  
  bool line[H],row[W];
  
  rep(i, H) {
    line[i]=false;
    rep(j, W) if(a[i][j] == '#') {line[i]=true; break;}
  }
  
  rep(j, W) {
    row[j]=false;
    rep(i, H) if(a[i][j] == '#') {row[j]=true; break;}
  }
  
  rep(i, H) {
    if(line[i]==false) continue;
    rep(j, W) if(row[j]==true) cout << a[i][j];
    cout << endl;
  }
  return 0;
}
