#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr long double EPS = 1e-15;
const long double PI = acos(-1);
constexpr int inf = 2e9;
constexpr ll INF = 2e18;
constexpr ll MOD = 1e9+7;
constexpr ll MOD1 = 998244353;
typedef pair<ll,ll> P;

//#define all(v) (v).begin(), (v).end()
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

void solve() {
  int n;
  cin >> n;
  map<int,int> mp;
  REP(i,n) {
    int a;
    cin >> a;
    if (sz(mp) == 0) {
      mp[a]++;
      continue;
    }
    auto itr = mp.upper_bound(a - 1);
//    cout << (*itr).fi << endl;
    if (itr == mp.begin()) {
      mp[a]++;
    } else {
      itr--;
      int k = (*itr).fi;
      if (mp[k] == 1) {
        mp.erase(k);
        mp[a]++;
      } else {
        mp[k]--;
        mp[a]++;
      }
    }
    // for (auto p: mp) {
    //   cout << p.fi << " ";
    // }
    // cout << endl;
  }
  int ans = 0;
  for (auto p:mp) {
    ans += p.se;
  }
  cout << ans << endl;
}

int main(int argc, char *argv[]){

  /* Regular */
  int case_num = 1;
  if (argc > 1 && stoi(argv[1])) cin >> case_num;
  REP(case_no, case_num) {
    cerr << endl << "case " << case_no + 1 << endl;
    solve();
  }
  
  // /* AOJ */
  // solve();
  return 0;
}