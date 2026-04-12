#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repi(i, s, n) for (int i = (s); i < (n); i++)
#ifdef LOCAL
#define INPUT_FILE                   \
  ifstream in("atcoder-problems/arc071_a.txt"); \
  cin.rdbuf(in.rdbuf());
#define print_vec(v) \
rep(l, v.size()) { cout << v[l] << " "; } \
cout << endl;
#else
#define INPUT_FILE
#define print_vec(v)
#endif
#define CIN_OPTIMIZE \
  cin.tie(0);        \
  ios::sync_with_stdio(false);
typedef pair<int, int> P;
typedef long long ll;
typedef pair<ll, ll> pl;
const int INF = 100100100;
const ll LINF = 1e18+100;
const int MOD = 1e9 + 7;

int main() {
  INPUT_FILE CIN_OPTIMIZE;

  int N;
  cin >> N;

  map<char, int> m;
  rep(i, N) {
    map<char, int> t;
    string s;
    cin >> s;
    rep(j, s.size()) { t[s[j]]++; }
    if (i == 0) {
      m = t;
    } else {
      map<char, int> n;
      for (auto kv : t) {
        if(m[kv.first]) {
          n[kv.first] = min(kv.second, m[kv.first]);
        }
      }
      m = n;
    }
  }

  for (auto kv: m) {
    rep(i, kv.second) { cout << kv.first; }
  }
}