#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << (x) << '\n'
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

const int idx = 1e5 + 10, sum = 101, tight = 2;
int mod = 1e9 + 7;

int dp[idx][sum][tight];

int main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   string s;
   int d;
   cin >> s >> d;
   int n = s.length();
   vector <int> a;
   for (auto &i : s)
      a.push_back(i - '0');

   dp[n][0][0] = 1;
   dp[n][0][1] = 1;

   for (int i = n - 1; i >= 0; i--) {
      for (int m = 0; m < 2; m++) {
         for (int k = 0; k < d; k++) {
            for (int j = 0; j < 10; j++) {
               int x = (j + k) % d;
               if (m == 0) {
                  if (i == 0 && a[i] <= j)
                     continue;
                  dp[i][x][m] += dp[i + 1][k][m];
               } else {
                  if (j < a[i] && i != 0)
                     dp[i][x][m] += dp[i + 1][k][!m];
                  else if (j == a[i])
                     dp[i][x][m] += dp[i + 1][k][m];
               }
               dp[i][x][m] %= mod;
            }
         }
      }
   }

   cout << ((dp[0][0][1] + dp[0][0][0]) % mod + mod - 1) % mod << endl;

   return 0;
}