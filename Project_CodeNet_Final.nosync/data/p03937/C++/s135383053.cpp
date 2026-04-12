#include <cstdio>

const int MAX_RC = 10;
int R, C;
char grid[MAX_RC][MAX_RC];
bool seen[MAX_RC][MAX_RC];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

int main() {
  scanf(" %d %d ", &R, &C);
  bool doable = true;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      scanf("%c", &grid[r][c]);
    }
    scanf(" ");
  }
  int r = 0, c = 0;
  while (1) {
    int num = 0;
    seen[r][c] = true;
    int nnr, nnc, kk;
    for (int k = 0; k < 4; ++k) {
      int nr = dr[k] + r;
      int nc = dc[k] + c;
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (grid[nr][nc] == '.') continue;
      if (seen[nr][nc]) continue;
      ++num;
      if (num > 1) {
        doable = false;
        goto done;
      }
      nnr = nr;
      nnc = nc;
      kk = k;
    }
    if (num == 0) break;
    if (kk == 1 || kk == 0) {
      doable = false;
      break;
    }
    r = nnr;
    c = nnc;
  }
  done:
  if (doable) printf("Possible\n");
  else printf("Impossible\n");
}
