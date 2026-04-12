# include <cstdio>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int m = 0;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int H;
    scanf("%d", &H);
    if (i == 0) {
      ++cnt;
      m = H;
      continue;
    }
    if (H >= m) {
      ++cnt;
      m = H;
    }
  }
  printf("%d", cnt);
  fflush(stdout);
  return 0;
}
