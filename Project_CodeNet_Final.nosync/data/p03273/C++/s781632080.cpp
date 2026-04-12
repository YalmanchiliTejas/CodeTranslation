#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W, 0));
  REP(i, H) REP(j, W) cin >> A[i][j];
  while (true) {
    bool t = true;
    //縦
    REP(i, A[0].size()) {
      bool ok = true;
      REP(j, A.size()) {
        if (A[j][i] == '#') ok = false;
      }
      if (ok) {
        t = false;
        REP(j, A.size()) { A[j].erase(A[j].begin() + i); }
      }
    }
    //横
    REP(i, A.size()) {
      bool ok = true;
      REP(j, A[0].size()) {
        if (A[i][j] == '#') ok = false;
      }
      if(ok){
        t = false;
        A.erase(A.begin()+i);
      }
    }
    if (t) break;
  }
  REP(i,A.size()){
    REP(j, A[i].size()) { cout << A[i][j];
    }
    cout << endl;
  }
}