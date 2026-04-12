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
  int32 n,m;
  cin >> n >> m;
  vector<vector<bool>> adj(n, vector<bool>(n,false));
  REP(i,m){
    int32 a,b;
    cin >> a >> b;
    a--;b--;
    adj[a][b] = adj[b][a] = true;
  }
  vector<int32> perm;
  FOR(i,1,n)perm.pb(i);
  int32 ans = 0;
  do{
    bool flg = adj[0][perm[0]];
    REP(i,n-2){
      if(!adj[perm[i]][perm[i+1]]){
        flg = false;
        break;
      }
    }
    if(flg){
      // REP(i,n-1)cout << perm[i]+1;
      // cout << endl;
      ++ans;
    }
  }while(next_permutation(ALL(perm)));
  ANS(ans);
  return 0;
}