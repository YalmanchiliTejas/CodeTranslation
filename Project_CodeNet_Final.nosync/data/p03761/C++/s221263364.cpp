#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

map<char, int> isect;
int n;

int main() {
  cin >> n;
  string ss;
  cin >> ss;
  for (auto c : ss) {
    ++isect[c];
  }

  rep(i, 0, n - 1) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s) {
      ++mp[c];
    }
    for (auto c : isect) {
      isect[c.first] = min(c.second, mp[c.first]);
    }
  }

  bool isblank = true;
  for (auto e : isect) {
    rep(i, 0, e.second) {
      cout << e.first;
      isblank = false;
    }
  }
  if (isblank) {
    cout << endl;
  }
}
