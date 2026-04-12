#include <bits/stdc++.h>
#include <cassert>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
struct Edge
{
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;
// using Graph = vector<vector<int>>;

const long long INF = 1LL << 60;
const int INT_INF = 1000000000;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[8] = {-1, 0, 1, 1, -1, 1, 0, -1};

template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string N;
  int K;
  cin >> N >> K;
  static ll dp[110][2][5];
  int L = N.size();
  dp[0][0][0] = 1;
  for (int i = 0; i < L; i++)
  {
    const int di = N[i] - '0';
    for (int j = 0; j < 2; j++)
    {
      for (int k = 0; k < K + 1; k++)
      {
        for (int d = 0; d <= (j ? 9 : di); d++)
        {
          if (d == 0)
            dp[i + 1][j || (d < di)][k] += dp[i][j][k];
          else
            dp[i + 1][j || (d < di)][k + 1] += dp[i][j][k];
        }
      }
    }
  }
  cout << dp[L][1][K] + dp[L][0][K] << endl;
  return 0;
}

// 桁DP 0でない数字を何個持つかを保持する
// dp[決定した桁数][N未満確定か][0以外の数字が出た数] := i桁決めた時に0でない数がj個である．
