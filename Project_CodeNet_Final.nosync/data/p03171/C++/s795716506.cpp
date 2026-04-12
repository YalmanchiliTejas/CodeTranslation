#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs

const int MAXN = 3050;

int n;
int a[MAXN];
long long dp[MAXN][MAXN][2];

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int l = i, r = i + len - 1;
      for (int j = 0; j < 2; j++) {
        if (len == 1) {
          dp[l][r][j] = (j == 0 ? a[i] : -a[i]);
          continue;
        }
        long long x = dp[l + 1][r][1 - j] + (j == 0 ? a[l] : -a[l]);
        long long y = dp[l][r - 1][1 - j] + (j == 0 ? a[r] : -a[r]);
        if (j == 0) {
          dp[l][r][j] = max(x, y);
        } else {
          dp[l][r][j] = min(x, y);
        }
      }
    }
  }

  cout << dp[0][n - 1][0] << endl;

  return 0;
}
