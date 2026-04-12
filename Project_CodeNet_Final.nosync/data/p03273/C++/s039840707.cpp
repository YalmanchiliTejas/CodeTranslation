#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
using ll = long long;
using ull = unsigned long long;

int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<string>> v(h, vector<string>(w));
  vector<int> skipr(h, true), skipc(w, true);
  rep(i, h) {
    string s;
    cin>>s;
    rep(j, w) {
      v[i][j] = s[j];
      if (v[i][j] == "#") {
        skipr[i] = false;
        skipc[j] = false;
      }
    }
  }
  rep(i, h) {
    if (!skipr[i]) {
      rep(j, w) {
        if (!skipc[j]) {
          cout << v[i][j];
        }
      }
      cout << endl;
    }
  }
}
