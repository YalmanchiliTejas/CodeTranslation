#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const long long MOD = 1e9+7;
#define precout(val) cout << std::fixed << std::setprecision(20) << val;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;
// if(nextH >= 0 && nextH < H && nextW >= 0 && nextW < W)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A.begin(), A.end(), greater<long long>());

  if (N % 2 == 0) {
      long long res = 0;
      for (int i = 0; i < N/2 - 1; ++i) res += A[i] * 2;
      res += A[N/2 - 1];
      res -= A[N/2];
      for (int i = N/2 + 1; i < N; ++i) res -= A[i] * 2;
      cout << res << endl;
  }
  else {
      long long res1 = 0;
      for (int i = 0; i < N/2 - 1; ++i) res1 += A[i] * 2;
      res1 += A[N/2 - 1] + A[N/2];
      for (int i = N/2 + 1; i < N; ++i) res1 -= A[i] * 2;

      long long res2 = 0;
      for (int i = 0; i < N/2; ++i) res2 += A[i] * 2;
      res2 -= A[N/2] + A[N/2 + 1];
      for (int i = N/2 + 2; i < N; ++i) res2 -= A[i] * 2;
      cout << max(res1, res2) << endl;
  }
}
