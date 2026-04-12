#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int N; cin >> N;
   vector<int> A(3 * N);
   for (int i = 0; i < 3 * N; ++i) cin >> A[i], --A[i];
   vector<vector<int>> dp(N, vector<int>(N, -1e9));
   dp[A[0]][A[1]] = dp[A[1]][A[0]] = 0;
   vector<int> best_row(N, -1e9);
   best_row[A[0]] = 0;
   best_row[A[1]] = 0;
   int best = 0;
   int offset = 0;
   for (int cur = 2; cur + 2 < 3 * N; cur += 3) {
      if (A[cur] == A[cur + 1] && A[cur] == A[cur + 2]) {
         offset++;
         continue;
      }
      vector<tuple<int, int, int>> changes;
     changes.reserve(20 * N);
      if (A[cur] == A[cur + 1] || A[cur] == A[cur + 2] || A[cur + 1] == A[cur + 2]) {
         int diff = A[cur] ^ A[cur + 1] ^ A[cur + 2];
         int same = (A[cur] + A[cur + 1] + A[cur + 2] - diff) >> 1;
         for (int z = 0; z < N; ++z) {
            changes.emplace_back(diff, z, dp[same][z] + 1);
            changes.emplace_back(z, diff, dp[z][same] + 1);
         }
      }
      for (int i = 0; i < 3; ++i) {
         int x = A[cur + i];
         int y = A[cur + (i + 1) % 3];
         int z = A[cur + (i + 2) % 3];
         changes.emplace_back(y, z, dp[x][x] + 1);
         changes.emplace_back(z, y, dp[x][x] + 1);
         for (int t = 0; t < N; ++t) {
            changes.emplace_back(x, t, best_row[t]);
            changes.emplace_back(t, x, best_row[t]);
         }
      }
      for (int i = 0; i < 3; ++i) {
         for (int j = 0; j < 3; ++j) if (i ^ j) {
            changes.emplace_back(A[cur + i], A[cur + j], best);
         }
      }
      for (auto c : changes) {
         int x, y, z;
         tie(x, y, z) = c;
         dp[x][y] = max(dp[x][y], z);
         best = max(best, z);
         best_row[x] = max(best_row[x], z);
      }
   }
   best = max(best, dp[A.back()][A.back()] + 1);
   cout << best + offset << '\n';
   return 0;
}
