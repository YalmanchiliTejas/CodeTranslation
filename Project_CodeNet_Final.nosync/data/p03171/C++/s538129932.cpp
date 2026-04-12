#include <iostream>
#include <deque>

using namespace std;

typedef long long LL;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define TARO 0
#define JIRO 1

LL dp[3000][3000]; // dp[i][j] : i番目からj番目まででのX-Yの値
LL solve(int turn, deque<LL>& A, int i, int j) {
  if (dp[i][j] != -1)
    return dp[i][j];
  if (A.size() == 0)
    return 0;
  if (A.size() == 1)
    return (turn == TARO ? 1 : -1) * A.front();
  LL front = A.front(),
    back = A.back();
  A.pop_front();
  LL res = solve(1 - turn, A, i + 1, j) + (turn == TARO ? 1 : -1) * front;
  A.push_front(front);
  A.pop_back();
  LL res2 = solve(1 - turn, A, i, j - 1) + (turn == TARO ? 1 : -1) * back;
  A.push_back(back);
  if (turn == TARO)
    return dp[i][j] = res > res2 ? res : res2;
  return dp[i][j] = res < res2 ? res : res2;
}

int main() {
  int N;
  cin >> N;

  deque<LL> A;
  for (int i = 0; i < N; ++i) {
    LL a;
    cin >> a;
    A.PB(a);
  }
  REP(i, 3000)
    REP(j, 3000)
    dp[i][j] = -1; // dp[i][j] : i番目からj番目まででのX-Yの値
  cout << solve(TARO, A, 0, N - 1) << endl;
  return 0;
}
