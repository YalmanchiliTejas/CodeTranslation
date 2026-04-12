#include<cstdio>
#include<deque>
#define m (100000)
#define intq deque<int>

using namespace std;

int main(void) {
  int n;
  char s[m + 2];

  scanf("%d", &n);
  scanf("%s", s);

  s[n] = s[0];

  intq a(n + 2);

  int r = 0;
  int i;

  a[0] = 1;
  a[1] = 1;

  for (int i = 1; i < n+1; i++) {
    if (a[i]) {
      if (s[i] == 'o') {
        a[i+1] = a[i-1];
      } else {
        a[i+1] = 1 - a[i-1];
      }
    } else {
      if (s[i] == 'o') {
        a[i+1] = 1 - a[i-1];
      } else {
        a[i+1] = a[i-1];
      }
    }
  }


  if (a[n] == a[0] && a[n+1] == a[1])
    r = 1;

  if (!r) {
    a[1] = 0;
    for (int i = 1; i < n+1; i++) {
      if (a[i]) {
        if (s[i] == 'o') {
          a[i+1] = a[i-1];
        } else {
          a[i+1] = 1 - a[i-1];
        }
      } else {
        if (s[i] == 'o') {
          a[i+1] = 1 - a[i-1];
        } else {
          a[i+1] = a[i-1];
        }
      }
    }
    if (a[n] == a[0] && a[n+1] == a[1])
      r = 1;

    if (!r) {
      a[0] = 0;
      for (int i = 1; i < n+1; i++) {
        if (a[i]) {
          if (s[i] == 'o') {
            a[i+1] = a[i-1];
          } else {
            a[i+1] = 1 - a[i-1];
          }
        } else {
          if (s[i] == 'o') {
            a[i+1] = 1 - a[i-1];
          } else {
            a[i+1] = a[i-1];
          }
        }
      }
      if (a[n] == a[0] && a[n+1] == a[1])
        r = 1;

      if (!r) {
        a[1] = 1;
        for (int i = 1; i < n+1; i++) {
          if (a[i]) {
            if (s[i] == 'o') {
              a[i+1] = a[i-1];
            } else {
              a[i+1] = 1 - a[i-1];
            }
          } else {
            if (s[i] == 'o') {
              a[i+1] = 1 - a[i-1];
            } else {
              a[i+1] = a[i-1];
            }
          }
        }
        if (a[n] == a[0] && a[n+1] == a[1])
          r = 1;
      }
    }
  }

  if (r) {
    for (i = 0; i<n;i++) {
      if (a[i])
        printf("S");
      else
        printf("W");
    }
    printf("\n");
  } else
    printf("-1\n");

  return 0;

}