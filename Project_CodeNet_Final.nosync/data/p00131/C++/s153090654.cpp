#include <cstdio>
#include <cstring>
using namespace std;

int a[10];
int b[10];
int c[10];

int main() {
  int n, t;
  bool solved;
  scanf("%d", &n);
  for (int x=0; x<n; x++) {
    for (int i=0; i<10; i++) a[i] = 0;
    for (int i=0; i<10; i++) {
      for (int j=0; j<10; j++) {
        scanf("%d", &t);
        a[i] |= t<<j;
      }
    }

    solved = false;
    for (int i=0; i<(1<<10); i++) {
      memcpy(b, a, sizeof(a));
      b[0] ^= i;
      b[0] ^= i<<1;
      b[0] ^= i>>1;
      b[0] &= (1<<10)-1;
      b[1] ^= i;
      for (int j=1; j<10; j++) {
        b[j] ^= b[j-1];
        b[j] ^= b[j-1]<<1;
        b[j] ^= b[j-1]>>1;
        b[j] &= (1<<10)-1;
        if (j<9) {
          b[j+1] ^= b[j-1];
        }
      }
      if (!b[9]) {
        c[0] = i;
        for (int j=1; j<10; j++) {
          c[j] = b[j-1];
        }
        solved = true;
        break;
      }
    }

    if (solved) {
      for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
          if (j) putchar(' ');
          printf("%d", (c[i]>>j)&1);
        }
        putchar('\n');
      }
    }
  }

  return 0;
}