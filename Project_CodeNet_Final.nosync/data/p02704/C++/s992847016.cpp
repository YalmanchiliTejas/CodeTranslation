#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;

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
  int32 n;
  cin >> n;
  vector<int32> s(n),t(n);
  vector<uint64> u(n),v(n);
  REP(i,n)cin >> s[i];
  REP(i,n)cin >> t[i];
  REP(i,n)cin >> u[i];
  REP(i,n)cin >> v[i];
  vector<vector<uint64>> ans(n, vector<uint64>(n,0));
  REP(b,64){
    vector<vector<uint64>> tmp(n, vector<uint64>(n,2));
    REP(i,n)REP(j,n){
      if(s[i] == 1 && (u[i]>>b&1) == 0)tmp[i][j] = 0;
      if(s[i] == 0 && (u[i]>>b&1) == 1)tmp[i][j] = 1;
      if(t[j] == 1 && (v[j]>>b&1) == 0)tmp[i][j] = 0;
      if(t[j] == 0 && (v[j]>>b&1) == 1)tmp[i][j] = 1;
    }
    REP(_,4){
      REP(i,n){
        if(s[i] == 0 && (u[i]>>b&1) == 0){
          int32 m = 1;
          int32 yetcnt = 0;
          int32 yetj = -1;
          REP(j,n){
            if(tmp[i][j] == 0)m = 0;
            if(tmp[i][j] == 2){
              ++yetcnt;
              yetj = j;
            }
          }
          if(m == 1){
            if(yetcnt == 0){
              ANS(-1);
              return 0;
            }else if(yetcnt == 1){
              tmp[i][yetj] = 0;
            }
          }
        }else if(s[i] == 1 && (u[i]>>b&1) == 1){
          int32 s = 0;
          int32 yetcnt = 0;
          int32 yetj = -1;
          REP(j,n){
            if(tmp[i][j] == 1)s = 1;
            if(tmp[i][j] == 2){
              ++yetcnt;
              yetj = j;
            }
          }
          if(s == 0){
            if(yetcnt == 0){
              ANS(-1);
              return 0;
            }else if(yetcnt == 1){
              tmp[i][yetj] = 1;
            }
          }
        }
      }
      REP(i,n)REP(j,n){
        if(i < j)swap(tmp[i][j], tmp[j][i]);
      }
      swap(s,t);
      swap(u,v);
    }
    int32 f = 0;
    REP(i,n){
      int32 cnt = 0;
      int32 g = f;
      REP(j,n){
        if(tmp[i][j] == 2){
          tmp[i][j] = g;
          g ^= 1;
          ++cnt;
        }
      }
      if(cnt > 0)f ^= 1;
    }
    REP(_,2){
      REP(i,n){
        if(s[i] == 0){
          int32 m = 1;
          REP(j,n){
            m *= tmp[i][j];
          }
          if((u[i]>>b&1) != m){
            ANS(-1);
            return 0;
          }
        }else{
          int32 s = 0;
          REP(j,n){
            if(tmp[i][j] == 1)s = 1;
          }
          if((u[i]>>b&1) != s){
            ANS(-1);
            return 0;
          }
        }
      }
      REP(i,n)REP(j,n){
        if(i < j)swap(tmp[i][j], tmp[j][i]);
      }
      swap(s,t);
      swap(u,v);
    }
    REP(i,n)REP(j,n){
      ans[i][j] += tmp[i][j] << b;
    }
  }
  REP(i,n){
    REP(j,n){
      if(j != 0)cout << " ";
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}