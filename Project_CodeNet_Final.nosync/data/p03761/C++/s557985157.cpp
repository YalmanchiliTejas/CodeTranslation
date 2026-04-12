#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// #define int long long

#define LOG(variable) cout << #variable":\t" << (variable) << endl
#define LOGCON(i, container) for(int (i) = 0; (i) < (container).size(); ++(i)) cout << (i) << ":\t" << (container)[(i)] << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, r, n) for (int i = (r); i < (n); ++i)
#define REPR(i, n) for(int i = (n); i >= 0; --i) // from n to 0
#define REPRS(i, r, n) for(int i = (n); i >= (r); --i) // from n to r
#define REPOBJ(itr, obj) for(auto itr = (obj).begin(); itr != (obj).end() ; ++itr)
#define REPROBJ(itr, obj) for(auto itr = (obj).rbegin(), e = (obj).rend(); itr != e; ++itr)
#define COUTB(x) cout << (x) << "\n"
#define COUTS(x) cout << (x) << " "
#define PB push_back
#define SORT(obj) sort((obj).begin(), (obj).end())
#define SORTR(obj) sort((obj).begin(), (obj).end(), greater<>())
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define PI (acos(-1))
/***** MAIN *****/
signed main() {
  int n;
  cin >> n;
  string ss[n];
  REP(i,n) {
    cin >> ss[i];
  }
  vector<map<char,int>> vm(n);
  REP(i,n) {
    map<char,int> mp;
    REP(j,ss[i].length()) {
      ++mp[ss[i][j]];
    }
    vm[i] = mp;
  }
  for(char c = 'a'; c <= 'z'; ++c) {
    int min_count = 100;
    REP(i,n) {
      min_count = min(min_count, vm[i][c]);
    }
    REP(i,min_count) {
      cout << c;
    }
  }
  cout << "\n";
  return 0;
}
/***** MAIN *****/
