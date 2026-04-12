#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int H, W;
  cin >> H >> W;
  int kyori = -1;
  vector<vector<char>> A(H + 1, vector<char>(W + 1));
  REP(i, H) REP(j, W) {
    cin >> A[i][j];
    if (A[i][j] == '#') kyori++;
  }
  if(A[0][0]=='.'){
    puts("Impossible");
    return 0;
  }
  queue<pair<P, int>> que{};
  que.push(pair<P, int>(P(0, 0), 0));
  while (!que.empty()) {
    P now = que.front().first;
    int dis = que.front().second;
    que.pop();
    if (A[now.first + 1][now.second] == '#')
      que.push(pair<P, int>(P(now.first + 1, now.second), dis + 1));
    if (A[now.first][now.second + 1] == '#')
      que.push(pair<P, int>(P(now.first, now.second + 1), dis + 1));
    if (now.first == H - 1 && now.second == W - 1&&dis==kyori) {
      puts("Possible");
      return 0;
    }
  }
  puts("Impossible");
}