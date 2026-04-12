#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

int readint() {
   int ret = 0, d;
    d = getchar();
    while (d < 48 || d > 57)
       	d = getchar();
    do {
        ret = ret * 10 + d - 48;
        d = getchar();
    } while (d > 47 && d < 58);
    return ret;
}

const int MAXN = 1e3 + 5;

int a[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
   int n, m; cin >> n >> m;

   int uk = 0;
   REP(i, n) REP(j, m) {
      char c; cin >> c;
      if(c == '#') {
         a[i][j] = 1;
         uk ++;
      }
   }

   dp[0][0] = 1;

   REP(i, n) REP(j, m) {
      if(!a[i][j]) {
         dp[i][j] = 0;
         continue;
      }

      if(i - 1 >= 0 && dp[i - 1][j]) dp[i][j] = 1;
      if(j - 1 >= 0 && dp[i][j - 1]) dp[i][j] = 1;
   }

   if(dp[n - 1][m - 1] && uk == n + m - 1) cout << "Possible";
   else cout << "Impossible";
}
