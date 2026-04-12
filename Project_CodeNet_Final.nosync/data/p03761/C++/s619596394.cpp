#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-7)
#define INF (1<<25)
#define PI (acos(-1))

#define FOR(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define REP(i,n) FOR(i,0,n)

#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

int main() {
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  vector<int> cnt(26,INF), tmp(26,0);
  REP(i,n) {
    REP(j,26) tmp[j] = 0;
    REP(j,s[i].size()) tmp[s[i][j]-'a']++;
    REP(j,26) chmin(cnt[j], tmp[j]);
  }
  string ans;
  REP(i,26) REP(j,cnt[i]) ans.push_back(i+'a');
  cout << ans << endl;
  return 0;
}
