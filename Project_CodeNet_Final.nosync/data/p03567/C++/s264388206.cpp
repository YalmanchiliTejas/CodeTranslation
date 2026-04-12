#include <cstdio>

int main() {
  char s[10];
  scanf("%s", s);
  int i = 0;
  while (1) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      printf("Yes");
      break;
    } else if (s[i+1] == '\0') {
      printf("No");
      break;
    }
    ++i;
  }
  return 0;
}
