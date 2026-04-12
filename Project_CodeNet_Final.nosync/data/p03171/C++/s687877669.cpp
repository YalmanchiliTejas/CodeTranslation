//In The Name Of God
#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define L(x) (2*(x))
#define R(x) ((2*(x))+1)
#define pii pair<int, int>
#define pb push_back
using namespace std;
const int N = 3e3 + 5, Mod = 1e9 + 7, P = 727, Lg = 22, TOF = 1900, Inf = 3e18 + 10;

long long Dp[N][N], A[N];
int main(){
      ios_base::sync_with_stdio(0); cin.tie(0);
      int n; cin >> n;
      for(int i = 1; i <= n; i++)
            cin >> A[i];
      for(int i = 1; i <= n; i++)
            Dp[i][i] = A[i];
      for(int i = 2; i <= n; i++)
            for(int j = 1; j <= n - i + 1; j++)
                  Dp[j][j + i - 1] = max(-Dp[j][j + i - 2] + A[j + i - 1], -Dp[j + 1][j + i - 1] + A[j]);
      return cout << Dp[1][n], 0;
}

