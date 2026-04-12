#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
const int MOD = 1000000007;
typedef long long ll;
ll N, D, X;
typedef vector<int> Vec;
typedef vector<Vec> Mat;
void mat_mul(Vec &A, const Vec &B) {
  const int n = A.size();
  Vec col(n);
  REP(j,n) {
    ll s = 0;
    for(int k = 0; k <= j; ++k) {
      ll a = A[j - k];
      ll b = B[k];
      s += a * b;
      s %= MOD;
    }
    col[j] = s;
  }
  A = move(col);
}
Mat mat_pow(Mat A, ll n) {
  Vec col(A.size(),0);
  col[0] = 1;
  Vec a(A.size());
  REP(i,A.size()) a[i] = A[i][0];
  for(; n > 0; n >>= 1) {
    if(n & 1) mat_mul(col,a);
    mat_mul(a,a);
  }
  Mat res(A.size(), Vec(A.size(), 0));
  REP(i,A.size()) REP(j,A.size()) {
    if(i - j >= 0) res[i][j] = col[i - j];
  }
  return res;
}
void mat_print(Mat A) {
  const int n = A.size();
  REP(i,n) {
    REP(j,n) {
      cerr << ' ' << A[i][j];
    }
    cerr << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  while(true) {
    cin >> N >> D >> X;
    if(N == 0 && D == 0 && X == 0) break;
    Mat A(N+1, Vec(N+1, 0));
    REP(i,N+1) {
      for(int j = max<int>(i - X + 1, 0); j <= i; ++j) {
        A[i][j] = 1;
      }
    }
    Mat B = mat_pow(A, D);
    cout << B[N][0] << endl;
  }
}