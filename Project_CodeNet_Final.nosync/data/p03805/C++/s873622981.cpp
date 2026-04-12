#include <bits/stdc++.h>
#define REP(i,a,b) for(int(i)=(a);(i)<(b);++(i))
#define RREP(i,a,b) for(int(i)=(a)-1;(i)>=(b);--(i))
#define ALL(x) (x).begin(),(x).end()
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)
using namespace std;
typedef long long ll;

int main()
{
  int N,M;
  cin >> N >> M;

  // 隣接行列
  // int G[15][15];
  vector<vector<int>> G(N, vector<int>(N,0));
  REP(i,0,M) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    G[a][b] = 1; G[b][a] = 1;
  }

  // 1~N-1の順列
  // vector<int> perm(N);
  int perm[15];
  REP(i,0,N) perm[i] = i;

  int ans = 0; // 1からのpathの数
  do {
    // perm[0:N] が繋がっているか？
    bool is_connected = true;
    REP(i,0,N-1) {
      if (G[perm[i]][perm[i+1]] == 0) {
        is_connected = false;
        break;
      }
    }
    if (is_connected) ++ans;
  } while (next_permutation(perm+1, perm+N)); // 先頭は0に固定

  cout << ans << endl;

  return 0;
}
