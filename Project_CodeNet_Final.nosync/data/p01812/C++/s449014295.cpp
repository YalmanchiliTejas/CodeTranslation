#include <iostream>
#include <queue>
#define REP(i, a, n) for(int i = ((int) a); i < ((int) n); i++)
#define INF 100000000
using namespace std;
typedef pair<int, int> pii;

int N, M, K, D[16], V[100][100];
bool visited[1 << 16];

int main(void) {
  cin >> N >> M >> K;
  REP(i, 0, M) cin >> D[i], D[i]--;
  REP(i, 0, N) REP(j, 0, K) {
    int v; cin >> v; v--;
    V[i][j] = -1;
    REP(k, 0, M) if(i == D[k]) REP(l, 0, M) if(v == D[l]) V[i][j] = l;
  }
  REP(i, 0, 1 << M) visited[i] = false;

  queue<pii> q;
  q.push(pii((1 << M) - 1, 0));

  while(q.size()) {
    int s = q.front().first, d = q.front().second;
    q.pop();

    if(visited[s]) continue;
    visited[s] = true;

    if(s == 0) {
      cout << d << endl;
      break;
    }

    REP(i, 0, K) {
      int t = 0;
      REP(j, 0, M) if(((s >> j) & 1) && V[D[j]][i] >= 0) t = t | (1 << V[D[j]][i]);
      q.push(pii(t, d + 1));
    }
  }

  return 0;
}