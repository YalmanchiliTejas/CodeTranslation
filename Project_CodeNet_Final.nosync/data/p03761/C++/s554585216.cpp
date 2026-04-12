#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5 << 28, MOD = 1e9 + 7;

int N;
vector<string> V;
void input() {
  cin >> N;
  V.resize(N);
  rep(i, 0, N - 1) { cin >> V[i]; }
}
void solve() {
  vector<map<char, int>> mp(N);
  rep(i, 0, N - 1) {
    for (auto c : V[i]) {
      mp[i][c]++;
    }
  }
  map<char, int> a;
  rep(i, 0, 25) {
    char ch = char(i + 'a');
    int val = INF;
    rep(j, 0, N - 1) { val = min(val, mp[j][ch]); }
    a[ch] = val;
  }
  for (auto x : a) {
    while (x.second) {
      cout << x.first;
      x.second--;
    }
  }
  cout << endl

      ;
  ;
}
signed main() {
  input();
  solve();
  return 0;
}