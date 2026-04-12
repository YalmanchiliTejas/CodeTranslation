#include <cstdio>

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  int ofs = 0;
  for (int i = 0; i < Q; ++i) {
    int q, k;
    scanf("%d %d", &q, &k);
    if (q == 0) {
      int res = (ofs+k) % N;
      if (res == 0) res = N;
      printf("%d\n", res);
    } else if (q == 1) {
      ofs += k;
      if (ofs >= N) ofs -= N;
    }
  }
}

