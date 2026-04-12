#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3010;
const ll inf = 1e17;
int a[N], n;
ll dp[N][N]; // length and left position

ll solve(int i, int j){
   ll &dp = ::dp[i][j];
   if (dp != -1) return dp;
   if (i == j) return dp = a[i];
   dp = max(a[i] - solve(i + 1, j), a[j] - solve(i, j - 1));
   return dp;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.precision(10);
   cout << fixed;
   cin >> n;
   for (int i = 0; i < n; ++i)
      cin >> a[i];
   memset(dp, -1, sizeof(dp));
   cout << solve(0, n - 1) << '\n';
   return 0;
}