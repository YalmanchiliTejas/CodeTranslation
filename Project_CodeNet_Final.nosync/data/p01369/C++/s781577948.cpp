#include <stdio.h>
#include <string.h>

int main(void) {
  int i, j, ans;
  char h[30] = "111111110000000001111011101";
  while( 1 ) {
    ans = 0;
    char s[100];
    scanf("%s", s);
    if(s[0] == '#') break;
    for(i = 0; i < strlen(s); ++i) s[i] -= 'a' - 1;
    for(i = 1; i < strlen(s); ++i) if(h[s[i]] != h[s[i - 1]]) ++ans;
    printf("%d\n", ans);
  }
  return 0;
}
