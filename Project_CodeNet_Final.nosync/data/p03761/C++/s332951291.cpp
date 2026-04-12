#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<string> s(n);
  map<char,int> m;
  rep(i,n) cin >> s[i];
  rep(i,n) {
    if (i==0) {
      rep(j,s[i].size()) {
        m[s[i][j]]++;
      }
    } else {
      map<char,int> mt;
      rep(j,s[i].size()) {
        mt[s[i][j]]++;
      }
      for (auto a: m) {
        if (mt.count(a.first)) {
          if (mt[a.first] < a.second) m[a.first] = mt[a.first];
        } else m.erase(a.first);
      }
    }
  }
  for (auto a: m) {
    rep(i,a.second) cout << a.first;
  }
  cout << endl;
  return 0;
}