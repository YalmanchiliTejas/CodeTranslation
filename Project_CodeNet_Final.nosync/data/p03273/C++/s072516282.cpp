#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll h, w;
  cin >> h >> w;
  vector<string> ah(w, "");
  rep(i, h) {
    string s;
    cin >> s;
    bool is_alldot = true;
    for(char c : s) {
      if (c == '#') is_alldot = false;
    }
    if (!is_alldot) {
      rep(j, ll(s.size())) ah[j] += s[j];
    }
  }

  for(int i = w-1; i >= 0; i--) {
    bool is_alldot = true;
    for(char c : ah[i]) {
      if (c == '#') is_alldot = false;
    }
    if (is_alldot) {
      ah.erase(ah.begin()+i);
    }
  }

  rep(i, ll(ah[0].size())) {
    rep(j, ll(ah.size())) {
      cout << ah[j][i];
    }
    cout << endl;
  }

  return 0;
}
