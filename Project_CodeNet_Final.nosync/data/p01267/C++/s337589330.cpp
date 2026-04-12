#include <iostream>
using namespace std;

int N, A, B, C, X;
int Y[210];

int solve() {
  int cur = 0;
  for (int i = 0; i <= 10000; ++i) {
    if (Y[cur] == X) ++cur;
    if (cur == N) return i;
    X = (X * A + B) % C;
  }
  return -1;
}

int main() {
  while (cin >> N >> A >> B >> C >> X) {
    if (N == 0) break;
    for (int i = 0; i < N; ++i) cin >> Y[i];
    cout << solve() << endl;
  }
}
