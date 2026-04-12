#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int add(int x, int y) {
   x += y;
   if (x >= MOD) x -= MOD;
   return x;
}

int mult(int x, int y) {
   return (long long) x * y % MOD;
}

int pw(int x, int y) {
   int ans = 1;
   for (; y > 0; y >>= 1, x = mult(x, x)) if (y & 1) ans = mult(ans, x);
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   int N, A, B, C, D;
   cin >> N >> A >> B >> C >> D;
   vector<int> fact(N + 1);
   vector<int> ifact(N + 1);
   vector<vector<int>> powIfact(N + 1, vector<int>(N + 1));
   fact[0] = 1;
   ifact[0] = 1;
   for (int i = 1; i <= N; ++i) {
      fact[i] = mult(fact[i - 1], i);
      ifact[i] = pw(fact[i], MOD - 2);
   }
   for (int i = 0; i <= N; ++i) {
      powIfact[i][0] = 1;
      for (int j = 1; j <= N; ++j) {
         powIfact[i][j] = mult(powIfact[i][j - 1], ifact[i]);
      }
   }
   vector<int> dp(N + 1);
   dp[N] = 1;
   for (int z = A; z <= B; ++z) {
      vector<int> ndp = dp;
      for (int i = 1; i <= N; ++i) {
         for (int j = 1; j <= D && j * z <= i; ++j) {
            if (j >= C) {
               /// fact(i) / fact(i - j * z) / fact(j) ^ z /
               int coeff = fact[i];
               coeff = mult(coeff, ifact[i - j * z]);
               coeff = mult(coeff, powIfact[z][j]);
               coeff = mult(coeff, ifact[j]);
               ndp[i - j * z] = add(ndp[i - j * z], mult(dp[i], coeff));
            }
         }
      }
      dp = ndp;
   }
   cout << dp[0] << "\n";
}
