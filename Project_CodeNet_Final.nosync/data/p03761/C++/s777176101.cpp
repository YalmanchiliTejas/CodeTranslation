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
      map<char,int> ms;
      rep(j,s[i].size()) {
        ms[s[i][j]]++;
      }
      for (auto a: m) {
        char k = a.first;
        int v = a.second;
        if (ms.count(k)) {
          if (ms[k] < v) m[k] = ms[k];
        } else m.erase(k);
      }
    }
  }
  for (auto a: m) {
    char k = a.first;
    int v = a.second;
    rep(i,v) cout << k;
  }
  cout << endl;
  return 0;
}