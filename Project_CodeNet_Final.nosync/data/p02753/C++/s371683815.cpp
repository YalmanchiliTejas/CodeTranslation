#include <bits/stdc++.h>

int main(void) {
  char s1, s2, s3;
  scanf(" %c %c %c", &s1, &s2, &s3);
  if(s1 == s2 && s2 == s3) puts("No");
  else puts("Yes");
  return 0;
}
