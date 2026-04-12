#include <cstdio>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

int n, m;
int g[8][8];
int dp[1 << 8][8];

int main(){
  scanf("%d%d", &n, &m);
  rep(i, m){
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a][b] = g[b][a] = 1;
  }

  dp[(1 << n) - 2][0] = 1;
  for(int i = (1 << n) - 3; i >= 0; --i){
    rep(j, n){
      rep(k, n){
        if(g[j][k] && !(i >> j & 1)){
          dp[i][j] += dp[i | 1 << j][k];
        }
      }
    }
  }
  int a = 0;
  rep(i, n){
    a += dp[0][i];
  }
  printf("%d\n", a);
  return 0;
}