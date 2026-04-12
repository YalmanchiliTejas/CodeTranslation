#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;

vector<vector<char>> cart_product(const vector<vector<char>>& v) {
  vector<vector<char>> s = {{}};
  for (auto& u : v) {
    vector<vector<char>> r;
    for (auto& x : s) {
      for (auto y : u) {
        r.push_back(x);
        r.back().push_back(y);
      }
    }
    s.swap(r);
  }
  return s;
}

bool ok1(ll n, const string& ans, const string& s) {
  if (ans[0] == 'S') {
    if (s[0] == 'o') {
      return ans[n - 1] == ans[1];
    } else {
      return ans[n - 1] != ans[1];
    }
  } else {
    if (s[0] == 'o') {
      return ans[n - 1] != ans[1];
    } else {
      return ans[n - 1] == ans[1];
    }
  }
}

bool ok2(ll n, const string& ans, const string& s) {
  if (ans[n - 1] == 'S') {
    if (s[n - 1] == 'o') {
      return ans[n - 2] == ans[0];
    } else {
      return ans[n - 2] != ans[0];
    }
  } else {
    if (s[n - 1] == 'o') {
      return ans[n - 2] != ans[0];
    } else {
      return ans[n - 2] == ans[0];
    }
  }
}

int main() {
  //
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<char>> v = {{'S', 'W'}, {'S', 'W'}};
  vector<vector<char>> start = cart_product(v);
  for (auto& st : start) {
    string ans(n, ' ');
    // cout << st[0] << "," << st[1] << "," << st[2] << endl;
    rep(i, 2) ans[i] = st[i];
    REP(i, 1, n - 1) {
      if (ans[i] == 'S') {
        if (s[i] == 'o') {
          ans[i + 1] = ans[i - 1];
        } else {
          if (ans[i - 1] == 'S') {
            ans[i + 1] = 'W';
          } else {
            ans[i + 1] = 'S';
          }
        }
      } else {
        if (s[i] == 'o') {
          if (ans[i - 1] == 'S') {
            ans[i + 1] = 'W';
          } else {
            ans[i + 1] = 'S';
          }
        } else {
          ans[i + 1] = ans[i - 1];
        }
      }
    }
    if (ok1(n, ans, s) && ok2(n, ans, s)) {
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
