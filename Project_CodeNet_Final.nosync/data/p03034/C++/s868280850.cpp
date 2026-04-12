#include <bits/stdc++.h>
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define IFOR(i, m, n) for(int i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const ll INF = 1e18;
/* テンプレートここまで */

int main() {
  ll n; cin >> n;
  vector<ll> s(n); REP(i, n) cin >> s[i];
  ll ans = 0;
  FOR(c,1,n-1){
    ll l = 0;
    ll r = n-1;
    ll score = 0;
    if((n-1)%c == 0){
      for( ; l<r ; l+=c, r-=c){
        score += s[l] + s[r];
        ans = max(ans,score);
      }
    }else{
      for(; r>c ;l+=c, r-=c){
        score += s[l] + s[r];
        ans = max(ans,score);
      }
    }
  }
  cout << ans << endl;
}