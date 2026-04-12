#include <atcoder/segtree>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int op(int a, int b) { return max(a, b); }
int e() { return -1L; }

int V;
bool f(int a) { return a < V; }

int main(void) {
  ios::sync_with_stdio(false);
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i, N) { cin >> A[i]; }
  atcoder::segtree<int, op, e> seg(A);

  rep(i, Q) {
    int T;
    cin >> T;
    if (T == 1) {
      int X;
      int V;
      cin >> X >> V;
      X--;
      seg.set(X, V);
    } else if (T == 2) {
      int L, R;
      cin >> L >> R;
      L--;
      int answer = seg.prod(L, R);
      cout << answer << endl;
    } else {
      int X;
      cin >> X >> V;
      X--;
      int answer = seg.max_right<f>(X) + 1;
      cout << answer << endl;
    }
  }
  return 0;
}
