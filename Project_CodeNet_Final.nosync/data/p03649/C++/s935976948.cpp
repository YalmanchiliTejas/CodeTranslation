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
#define mp make_pair

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int64 n;
  cin >> n;
  vector<int64> a(n);
  REP(i,n){
    cin >> a[i];
  }
  int64 ans = 0;
  int64 prevans = 0;
  while(true){
    int64 asum = 0;
    REP(i,n)asum += a[i] / n;
    REP(i,n){
      int64 x = a[i] / n;
      x = max<int64>(0,x);
      ans += x;
      a[i] -= x * n;
      a[i] -= x;
    }
    // ANS(ans);
    REP(i,n){
      a[i] += ans - prevans;
      // cout << a[i] << " ";
    }
    // cout << endl;
    prevans = ans;
    bool flg = true;
    REP(i,n){
      if(a[i] >= n){
        flg = false;
        break;
      }
    }
    if(flg)break;
  }
  ANS(ans);
  return 0;
}