#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <utility> // pair make_pair
#include <algorithm> // next_permutation

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define fill(x,y) memset(x,y,sizeof(x))

using namespace std;
using Graph = vector<set<int> >;

int main() {
  int N, M; cin >> N >> M;

  Graph G(N);
  
  for (int i = 0; i < M; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G[a].insert(b);
    G[b].insert(a);
  }

  int A[N];
  for (int i = 1; i < N; i++) {
    A[i] = i;
  }
  int cnt = 0;
  do {
    bool path = 1;
    for (int i = 1; i < N; i++) {
      if (i == 1) {
        if (!G[0].count(A[i])) {
          // cout << "0: " << A[i] << endl;
          path = 0;
          break;
        }
      } else if (!G[A[i-1]].count(A[i])) {
        // cout << A[i-1] << ": " << A[i] << endl;
        path = 0;
        break;
      }
    }
    if (path) cnt++;
  } while (next_permutation(A + 1, A + N));

  cout << cnt << endl;
}
