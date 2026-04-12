#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define dbg(x) cerr << #x << ": " << x << endl;
#define dbg2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define dbg3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define dbgB(value, size) cerr<<#value<<": "<<bitset<size>(value) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

template<typename T>
void print1(T begin, T end) {
  while (begin != end) {
    cout << (*begin) << " ";
    *begin++;
  }
  cout << endl;
}

template<typename T>
void print2(T Array, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << " " << Array[i][j];
    }
    cout << endl;
  }
}

void print() { std::cerr << endl; }
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cerr << head << " ";
  print(std::forward<Tail>(tail)...);
}

template<class T>
void Add(T &a, const T &b, const T &mod=1e9+7) {
  int val = (a % mod) + (b % mod);
  if (val < 0) { val += mod; }
  a = val;
}

// ------------------------------------------------------------------------------------------

string K;
int D;

int dp[11111][2][111];

signed main() {
  cin >> K >> D;
  int n = K.size();

  dp[0][0][0] = 1;
  for (int digit = 0; digit < n; digit++) {
    for (int smaller : {0, 1}) {
      for (int modD = 0; modD < D; modD++) {
        int lim = (smaller == 1 ? 9 : K[digit] - '0');
        for (int num = 0; num <= lim; num++) {
          Add(dp[digit+1][smaller || num < lim][(modD + num) % D], dp[digit][smaller][modD]);
        }
      }
    }
  }

  int ans = 0;
  for (int smaller : {0, 1}) {
    Add(ans, dp[n][smaller][0]);
  }
  Add(ans, -1LL);

  cout << ans << endl;

  return 0;
}