#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 h,w;
  cin >> h >> w;
  vector<string> a(h);
  REP(i,h)cin >> a[i];
  set<int32> x,y;
  REP(i,h){
    map<char,int32> mp;
    REP(j,w)mp[a[i][j]]++;
    if(mp['#'] == 0)x.insert(i);
  }
  REP(j,w){
    map<char,int32> mp;
    REP(i,h){
      mp[a[i][j]]++;
    }
    if(mp['#'] == 0)y.insert(j);
  }
  REP(i,h){
    if(x.count(i))continue;
    REP(j,w){
      if(y.count(j))continue;
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
