#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << x << endl
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i, H) cin >> S[i];

  vector<string> T;
  rep(i, H) {
    bool existsblack = false;
    rep(j, W) if(S[i][j] == '#') {
      existsblack = true;
      break;
    }
    if(existsblack) T.push_back(S[i]);
  }
  vector<bool> iswhitecl(W, true);
  rep(j, W) {
    rep(i, T.size()) if(T[i][j] == '#') {
      iswhitecl[j] = false;
      break;
    }
  }

  rep(i, T.size()) {
    rep(j, W) if(!iswhitecl[j]) cout << T[i][j];
    cout << endl;
  }
  return 0;
}