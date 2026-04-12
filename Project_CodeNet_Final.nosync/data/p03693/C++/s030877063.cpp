#include <cstdio>

int main() {
  int g, b;
  scanf("%*d %d %d", &g, &b);

  int gb = 10*g + b;
  if (gb % 4 == 0) {
    puts("YES");
  } else {
    puts("NO");
  }
}