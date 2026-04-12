#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const int INF = 1000000;
const double PI=3.14159265359;

int main(){

  ll h,w;cin>>h>>w;
  string s[h];
  rep(i,0,h)cin>>s[i];
  ll x=0;
  rep(i,0,h){
    ll count=0;
    rep(j,0,w){
      if(s[i][j]=='#'){
        if(count==0)if(x!=j){
          out("Impossible");
          return 0;
        }
        x=j;
        count++;
      }
    }
  }
  out("Possible");



  return 0;
}
