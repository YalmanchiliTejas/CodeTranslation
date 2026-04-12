#include <bits/stdc++.h>
using namespace std;

int H, W, N=0;
char M[10][10];

int main() {
  memset(M, 0, sizeof(M));
  scanf("%d%d", &H, &W);
  for(int i = 0; i < H; ++i)
    scanf("%s", M[i]);

  for(int i = 0; i < H; ++i)
    for(int j = 0; j < W; ++j)
      if(M[i][j] == '#') ++N;

  printf("%s\n", N==W+H-1 ? "Possible" : "Impossible");
  return 0;
}
