#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int64_t dp[MAXN][MAXN];

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int l = N - 1; l >= 0; l--)
  {
    for (int r = l; r < N; r++)
    {
      if (l == r)
        dp[l][r] = A.at(l);
      else
        dp[l][r] = max(A.at(l) - dp[l + 1][r], A.at(r) - dp[l][r - 1]);
    }
  }
  cout << dp[0][N - 1] << endl;
}
