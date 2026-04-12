#include <bits/stdc++.h>
using namespace std;

long long rec(int N, long long X) {
  if (N == 0) {
    if (X == 0) return 0;
    if (X == 1) return 1;
  }
  // レベル N-1 のバンとパティ
  long long bp = (1LL << (N+1)) - 3;
  // レベル N-1 のパティ
  long long p = (1LL << N) - 1;
  if (X == 1) return 0;
  else if (X <= 1 + bp) return rec(N-1, X-1);
  else if (X == 1 + bp + 1) return p + 1;
  else if (X <= 2 + 2*bp) return p + 1 + rec(N-1, X-2-bp);
  else return 2*p + 1;
}

int main() {
  int N; cin >> N;
  long long X; cin >> X;
  cout << rec(N, X) << endl;
}