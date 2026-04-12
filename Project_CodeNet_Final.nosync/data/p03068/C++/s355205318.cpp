#include <cstdio>
const int MAXN = 20;
char S[MAXN];
int K, N;

int main() {
  scanf(" %d%s%d", &N, S+1, &K);
  for (int i = 1; i <= N; ++i) {
    putchar((S[i] == S[K]) ? S[K] : '*');
  }
  putchar('\n');
  return 0;
}