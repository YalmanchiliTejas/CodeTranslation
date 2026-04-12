#include <iostream>
#include <algorithm>
#define REP(i, a, n) for(int (i) = (a); (i) <= (n); (i)++)
using namespace std;

int N, M, E[10][10];

bool is_valid(int* order) {
  REP(i, 1, N - 1) {
    if(!E[order[i]][order[i + 1]]) return false;
  }
  return true;
}

int main(void) {
  cin >> N >> M;
  REP(i, 1, N) REP(j, 1, N) E[i][j] = 0;
  REP(i, 1, M) {
    int a, b; cin >> a >> b;
    E[a][b] = 1;
    E[b][a] = 1;
  }

  int order[10];
  REP(i, 1, N) order[i] = i;

  long cnt = 0;
  do {
    if(is_valid(order)) cnt++;
  } while(next_permutation(order + 2, order + N + 1));

  cout << cnt << endl;

  return 0;
}
