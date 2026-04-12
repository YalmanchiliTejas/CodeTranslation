#include <algorithm>
#include <cstdio>

using namespace std;

#define rep(i, n) for (size_t i = 0; i < (n); i++)

int main() {
  size_t N, M;
  scanf("%ld%ld", &N, &M);
  bool es[N][N];
  rep(i, N) rep(j, N) es[i][j] = false;
  rep(j, M) {
    size_t a, b;
    scanf("%ld%ld", &a, &b);
    a--; b--;
    es[a][b] = es[b][a] = true;
  }
  size_t xs[N];
  rep(i, N) xs[i] = i;
  size_t c = 0;
  do {
    rep(i, N - 1)
      if (!es[xs[i]][xs[i+1]])
        goto escape;
    c++;
escape:
    ;
  } while (next_permutation(xs + 1, xs + N));
  printf("%ld\n", c);
  return 0;
}
