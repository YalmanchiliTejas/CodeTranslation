#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
template<typename T> inline void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H,W; cin >> H >> W;
  vector<string> S;
  vector<bool> WHITE_W(W, true);

  rep(h, H) {
    string tmp; cin >> tmp;
    bool all_white = true;
    rep(w, W) {
      if(tmp[w] == '#') {
        all_white = false;
        WHITE_W[w] = false;
      }
    }
    if(!all_white) {
      S.push_back(tmp);
    }
  }

  vector<string> ANS(S.size());

  rep(h, S.size()) {
    string ans = "";
    rep(w, W) {
      if(!WHITE_W[w]) {
        ans.push_back(S[h][w]);
      }
    }
    ANS[h] = ans;
  }

  rep(i, ANS.size()) cout << ANS[i] << endl;
}
