#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100][100];
string color[100];
//
// void dfs(int s) {
//   color[s] = "GRAY";
//   cout << "s:" << s+1 << endl;
//   // cout << "s:" << s << endl;
//   for (int t = 0; t < N; t++) {
//     if (A[s][t] == 1 && color[t] == "WHITE") {
//       dfs(t);
//     }
//   }
//   color[s] = "BLACK";
// }

int main() {
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      A[i][j] = 0;
    }
  }
  // for (int i = 0; i < N; i++) {
  //   color[i] = "WHITE";
  // }
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    A[a-1][b-1] = 1;
    A[b-1][a-1] = 1;
    // A[a][b] = 1;
    // A[b][a] = 1;
  }
  int p[N];
  for (int i = 0; i < N; i++) {
    p[i] = i;
  }
  int count = 0;
  do {
    int prev = p[0];
    if (prev != 0) {
      continue;
    }
    bool can_go = true;

    for (int i = 1; i < N; i++) {
      if (A[prev][p[i]] != 1) {
        // cout << "prev:" << prev << ", " << "next:" << p[i] << ", ng"<< endl;
        can_go = false;
        break;
      } else {
        // cout << "prev:" << prev << ", " << "next:" << p[i] << ", ok"<< endl;
      }
      prev = p[i];
    }
    // cout << can_go << endl;
    if (can_go) {
      // cout << "count up" << endl;
      count++;
    }
  } while(next_permutation(p, p+N));
  cout << count << endl;
}
