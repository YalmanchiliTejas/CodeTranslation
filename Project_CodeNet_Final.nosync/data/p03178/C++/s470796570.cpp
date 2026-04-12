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
#define tm aklsjdasjdasjdkdjjf

const int MAXN = 10050;
const int mod = (int) 1e9 + 7;

string s;
int n;
int d;
int dp[MAXN][105];

int main() { 

  getline(cin, s);
  scanf("%d", &d);

  for (int i = 0; i <= 9; i++) {
    dp[0][i % d]++;
  }
  for (int i = 1; i < MAXN; i++) {
    for (int j = 0; j < d; j++) {
      for (int k = 0; k <= 9; k++) {
        int sum = (j + k) % d;
        dp[i][sum] = (dp[i][sum] + dp[i - 1][j]) % mod;
      }
    }
  }

  n = sz(s);
  int sum = 0;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s[i] - '0'; j++) {
      int need = (d - sum) % d;
      if (n - i - 2 >= 0) {
        ans = (ans + dp[n - i - 2][need]) % mod;
        // cerr << "DP " << n - i - 1 << " " << need << " " << dp[n - i - 2][need] << endl; 
      } else {
        if (need == 0) {
          ans = (ans + 1) % mod; 
        }
      }
      sum = (sum + 1) % d;
    }
  }

  ans = ans - 1;
  if (ans < 0) {
    ans += mod;
  }
  if (sum == 0) {
    ans = (ans + 1) % mod;
  }

  cout << ans << endl;

  return 0;
}
