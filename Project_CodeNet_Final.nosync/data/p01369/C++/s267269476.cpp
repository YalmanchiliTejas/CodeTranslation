#include <bits/stdc++.h>
using namespace std;

int n;
char buf[100];
map<char, bool> is_right;

int main() {
  const char *p = "uyiophjklnm";
  for (int i=0; i<strlen(p); i++) {
    is_right[p[i]] = true;
  }

  while (1) {
    scanf(" %s", buf);
    n = strlen(buf);

    if (n == 1 && buf[0] == '#') return 0;

    int cnt = 0;
    bool flg = is_right[buf[0]];
    for (int i=1; i<n; i++) {
      if (flg != is_right[buf[i]]) cnt++;
      flg = is_right[buf[i]];
    }

    printf("%d\n", cnt);
  }
}