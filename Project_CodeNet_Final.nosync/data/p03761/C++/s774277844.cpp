#include <stdio.h>
#include <string.h>

int min(int a, int b) {
  return a < b ? a : b;
}

int main(void) {
  int i, j, ans[26], cnt[26], n;
  char s[60];
  scanf("%d", &n);
  for(i = 0; i < 26; ++i) ans[i] = 100;
  for(i = 0; i < n; ++i) {
    scanf("%s", s);
    for(j = 0; j < 26; ++j) cnt[j] = 0;
    for(j = 0; j < strlen(s); ++j) cnt[s[j] - 'a']++;
    for(j = 0; j < 26; ++j) ans[j] = min(cnt[j], ans[j]);
  }
  for(i = 0; i < 26; ++i) for(j = 0; j < ans[i]; ++j) printf("%c", i + 'a');
  return 0;
}