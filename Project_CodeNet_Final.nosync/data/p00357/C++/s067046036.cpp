#include <cstdio>
#include <cstring>

const int MAX_N = 500000;
int N;
const int K = 10;
int s[MAX_N];
int s2[MAX_N];
int cache[MAX_N];

int dp(int v) {
  if (v >= N) return false;
  if (v == N - 1) return true;
  if (cache[v] != -1) return cache[v];
  bool asdf = false;
  for (int i = v + 1; i < N; ++i) {
    if ((i - v) * 10 > s[v]) break;
    if (dp(i)) {
      asdf = true;
      break;
    }
  }
  cache[v] = asdf;
  return asdf;
}

int main() {
  scanf("%d", &N);
  memset(cache, -1, sizeof(cache));
  for (int i = 0; i < N; ++i) {
    scanf("%d", s + i);
  }
  bool a = dp(0);
  for (int i = 0; i < N; ++i) {
    s2[i] = s[N - i - 1];
  }
  memcpy(s, s2, MAX_N * sizeof(int));
  memset(cache, -1, sizeof(cache));
  printf(a && dp(0) ? "yes\n" : "no\n");
}