#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
#define watch(a) { std::cout << #a << " = " << a << "\n"; }
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }
template<class T, class V> istream& operator>> (istream& ist, pair<T, V>& p) { return ist >> p.first >> p.second; }
template<class T> ostream& operator<< (ostream& ost, pair<T, T>& p) { return ost << p.first << ", " << p.second; }
template<class T> istream& operator>> (istream& ist, vector<T>& vs) { for(auto& e: vs) ist >> e; return ist; }

typedef long long ll;
int const inf = 1<<29;

int main() {
  int H, W; cin >> H >> W;
  vector<string> vs(H);
  rep(i, H) {
    cin >> vs[i];
  }
  vector<bool> bsh(H), bsw(W);
  rep(i, H) {
    bsh[i] = 1;
    rep(j, W) {
      if (vs[i][j] == '#') {
        bsh[i] = 0;
      }
    }
  }
  rep(j, W) {
    bsw[j] = 1;
    rep(i, H) {
      if (vs[i][j] == '#') {
        bsw[j] = 0;
      }
    }
  }
  rep(i, H) {
    bool used = 0;
    rep(j, W) {
      if (bsh[i] || bsw[j]) {}
      else {
        used = 1;
        cout << vs[i][j];
      }
    }
    if (used) cout << "\n";
  }
}
