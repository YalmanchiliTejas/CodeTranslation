#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }

void solve() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++) {
    cin >> A[i];
  }

  vector<int> fH(H), fW(W);
  for(int i = 0; i < H; i++) {
    bool flag = true;
    for(int j = 0; j < W; j++) {
      if (A[i][j] != '.') {
        flag = false;
      }
    }
    if (!flag) fH[i] = 0; else fH[i] = 1;
  }

  for(int j = 0; j < W; j++) {
    bool flag = true;
    for(int i = 0; i < H; i++) {
      if (A[i][j] != '.') {
        flag = false;
      }
    }
    if (!flag) fW[j] = 0; else fW[j] = 1;
  }

  for (int i = 0; i < H; i++) {
    if (fH[i]) continue;
    for (int j = 0; j < W; j++) {
      if (fW[j]) continue;
      cout << A[i][j]; 
    }
    cout << endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(16);
  solve();
  return 0;
}