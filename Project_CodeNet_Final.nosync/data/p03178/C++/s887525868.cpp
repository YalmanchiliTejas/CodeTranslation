#include <cstdio>
#include <cstring>

const int MAXN = 1e4+4;
const int MAXD = 1e2+2;
const int MOD = 1e9+7;


int mem[MAXN][MAXD][2];
bool solved[MAXN][MAXD][2];
char C[MAXN];
int d, n;

int dp(int x, int sum, bool less) {
  if (x == n) return sum == 0;
  int &ret = mem[x][sum][less];
  if (solved[x][sum][less]) return ret;
  solved[x][sum][less] = 1;
  
  int k = less == 0 ? C[x] - '0' : 9;
  for (int i = 0; i <= k; ++i) {
    ret = (ret + dp(x+1, (sum+i) % d, less || (i < (C[x] - '0')))) % MOD;
  }

  return ret;
}

int main() {
  scanf("%s%d", C, &d);
  n = strlen(C);
  printf("%d\n", (dp(0, 0, 0)-1+MOD) % MOD);
  return 0;
}
