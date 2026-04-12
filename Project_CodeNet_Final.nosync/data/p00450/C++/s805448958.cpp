#include <cstdio>

int main() {
  for(;;) {
    int n; scanf("%d", &n);
    if(n==0) return 0;
    static int st[50010];
    int stlen = 0;
    auto st_ext = [&]() {
      if(stlen == 0) {
        st[stlen++] = 0;
        st[stlen++] = 0;
      }
    };
    for(int i = 0; i < n; ++i) {
      int x; scanf("%d", &x);
      if((stlen & 1) == x) {
        st_ext();
        ++st[stlen-1];
      } else if((i & 1) == 0) {
        st[stlen++] = 1;
      } else {
        st_ext();
        int y = st[--stlen];
        st_ext();
        st[stlen-1] += y + 1;
      }
    }
    int sum = 0;
    for(int i = 1; i < stlen; i += 2) {
      sum += st[i];
    }
    printf("%d\n", sum);
  }
}