// warm heart, wagging tail,and a smile just for you!
//
//                            ▒█████▒▒
//                             ██████████▒
//                             ▒████████████▒
//                            ██████████████████
//                           ████████████████████▒
//                          ▒██████████████████████▒
//                          ▒███████████████████████
//                      ▒████▒▒▒▒▒▒█████████████████▒
//                    ███▒▒▒▒▒▒██████████████████████▒▒▒
//                  ▒██▒▒███████████████████████▒▒▒▒▒██████
//                 ▒█████████████████████████▒▒▒▒▒▒█████████▒
//                 ▒█████████████████████▒▒▒▒▒▒██████████████
//                  ▒████         ████▒▒▒▒▒████         ████▒
//              ▒█████▒    ████    ▒▒▒▒███████    ████    ██████▒
//            ▒██▒▒▒▒▒    ██████    █████████    ██████    ██▒▒▒██▒
//           █████████   ████████   █████████   ████████   ▒▒▒▒█████
//          ▒█████████    ██████    ████████▒    ██████    █████████
//          ▒██████████    ████    █████▒▒▒▒▒▒    ████    ██████████
//           ████████████        ▒▒▒▒▒▒▒████████        ███████████▒
//       ▒██████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒███████████████████████████████████▒
//     ███▒▒▒▒▒▒▒▒▒▒▒▒█████████████████████████████████████████▒▒████████▒
//   ▒▒▒▒▒▒▒▒▒██████████████                         ███████▒▒▒▒███████████
//   █████████████████████████                     ███████▒▒▒██████████████▒
//   █████████████████████████████             ███████▒▒▒██████████████████▒
//   ██████████████████████████████████████████████████████████████████████
//    ██████████████████████████████████████████████████████████████████▒
//      ▒█████████████████▒▒▒▒▒▒▒██████████████████████████████████▒▒▒
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h,w;
  cin >> h >> w;

  vector<string> s(h);
  REP(i,h) cin >> s[i];
  
  vec H(h,0), W(w,0);
  REP(i,h){
    bool flag = true;
    REP(j,w){
      if(s[i][j] == '#') flag = false;
    }
    if(flag) H[i]++;
  }

  REP(j,w){
    bool flag = true;
    REP(i,h){
      if(s[i][j] == '#') flag = false;
    }
    if(flag) W[j]++;
  }

  REP(i,h){
    if(H[i]) continue;
    REP(j,w){
      if(W[j]) continue;
      cout << s[i][j];
    }
    cout << endl;
  }

  return 0;
}