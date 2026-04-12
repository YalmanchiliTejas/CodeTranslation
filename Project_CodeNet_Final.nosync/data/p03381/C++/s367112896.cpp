#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)

template<typename T> void pv(T a, T b) { for (T i = a; i < b; i++) cout << *i << ' '; cout << endl; }
template<typename T, typename U> void chmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> void chmax(T &x, U y) { if (x < y) x = y; }

int N;
int in[200010], xs[200010];

int main() {
  scanf("%d", &N);
  REP(i,N) {
    scanf("%d", &in[i]);
    xs[i] = in[i];
  }

  sort(xs, xs + N);

  int a = xs[N / 2 - 1], b = xs[N / 2];
  REP(i,N) {
    if (in[i] <= a) {
      cout << b;
    } else if (b <= in[i]) {
      cout << a;
    }
    cout << endl;
  }

  return 0;
}

