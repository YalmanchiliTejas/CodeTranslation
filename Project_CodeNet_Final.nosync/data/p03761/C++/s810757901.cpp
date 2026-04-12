#include <bits/stdc++.h>
using namespace std;

#define each(i, c) for (auto& i : c)
#define mkp(a, b) make_pair(a, b)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> Pll;
const ll MOD = 1e9+7;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << ": " << p.second << ")"; return os; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ", "; os << ")"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; each (i, m) os << i << ", "; os << "}"; return os; }

int main() {
  ll n;
  cin >> n;

  string ans;
  cin >> ans;
  for (ll i = 0; i < n-1; ++i) {
    string s;
    cin >> s;

    string tmp;
    vector<bool> mark(s.size());
    each (ch, ans) {
      for (ll j = 0; j < s.size(); ++j) {
        if (mark[j]) continue;
        if (ch == s[j]) {
          tmp += ch;
          mark[j] = true;
          break;
        }
      }
    }
    ans = tmp;
  }

  sort(ans.begin(), ans.end());

  cout << ans << endl;

  return 0;
}
