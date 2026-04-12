#include <stdio.h>

int main(void) {
  int i, j, n, cnt = 0;
  scanf("%d", &n);
  char st[n + 10];
  scanf("%s", st);
  bool t[n], s[n];
  for(i = 0; i < n; ++i) s[i] = (st[i] == 'o' ? true : false);
  bool b, bt1, bt2;
  for(j = 0; j < 4; ++j) {
    t[0] = j & 1, t[1] = j & 2;
    for(i = 2; i < n; ++i) {
      t[i] = (s[i - 1] && t[i - 1]) || (!s[i - 1] && !t[i - 1]);
      if(t[i]) t[i] = t[i - 2];
      else t[i] = !t[i - 2];
    }
    b = true;
    bt1 = (s[n - 1] && t[n - 1]) || (!s[n - 1] && !t[n - 1]);
    bt2 = (t[0] && t[n - 2]) || (!t[0] && !t[n - 2]);
    if(bt1 != bt2) b = false;
    bt1 = (s[0] && t[0]) || (!s[0] && !t[0]);
    bt2 = (t[n - 1] && t[1]) || (!t[n - 1] && !t[1]);
    if(bt1 != bt2) b = false;
    if(b) {
      for(i = 0; i < n; ++i) printf("%c", t[i] ? 'S' : 'W');
      return 0;
    }
  }
  printf("-1");
  return 0;
}