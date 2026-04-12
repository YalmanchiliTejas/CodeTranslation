#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
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
  int32 n;
  cin >> n;
  string s;
  cin >> s;
  vector<bool> ans(n);
  REP(mask,4){
    ans[0] = mask & 1;
    ans[1] = (mask >> 1) & 1;
    FOR(i,2,n){
      if(s[i-1] == 'o'){
        ans[i] = (ans[i-1] == ans[i-2]);
      }else{
        ans[i] = (ans[i-1] != ans[i-2]);
      }
    }
    if(s[n-1] == 'o'){
      if((ans[0] == ans[n-2]) != ans[n-1])continue;
    }else{
      if((ans[0] == ans[n-2]) == ans[n-1])continue;
    }
    if(s[0] == 'o'){
      if((ans[n-1] == ans[1]) != ans[0])continue;
    }else{
      if((ans[n-1] == ans[1]) == ans[0])continue;
    }
    REP(i,n){
      if(ans[i]){
        cout << "S";
      }else{
        cout << "W";
      }
    }
    cout << endl;
    return 0;
  }
  ANS(-1);
  return 0;
}