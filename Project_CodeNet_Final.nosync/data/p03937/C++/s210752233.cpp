#include <stdio.h>

int IsPossible() {
  char row[10];
  int H, W;
  scanf("%d %d", &H, &W);
  int last = 0;
  for(int i = 0; i < H; i++) {
    scanf(" %s", row);
    int x;
    for(x = 0; x < last; x++)
      if(row[x] == '#') return 0;
    if(row[last] != '#') return 0;
    for(x = last + 1; x < W; x++) {
      if(row[x] != '#') break;
      last++;
    }
    for(; x < W; x++) {
      if(row[x] == '#') return 0;
    }
  }
  return (last == W - 1);
}

int main() {
  puts(IsPossible() ? "Possible" : "Impossible");
  return 0;
}