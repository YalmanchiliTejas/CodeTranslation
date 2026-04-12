#include <iostream>
#include <vector>
using namespace std;
vector<int> used;
vector< vector<int> > connect;

int N, M;
int res = 0;
int dsf(int cur, int depth) {
  if(used[cur] == 1)
    return 0;
  if(depth == N)
    return 1;
  used[cur] = 1;
  for(int i=0; i < N; i++) {
    if(connect[cur][i] == 1) {
      res += dsf(i, depth + 1);
    }
  }
  used[cur] = 0;
  return 0;
}
int main(void) {
  cin >> N >> M;
  int a, b;
  used = vector<int>(N, 0);
  connect = vector< vector<int> >(N, vector<int>(N, 0));
  for(int i=0; i < M; i++) {
    cin >> a >> b;
    a--;
    b--;
    connect[a][b] = connect[b][a] = 1;
  }

  dsf(0, 1);
  printf("%d\n", res);
  return 0;
}
