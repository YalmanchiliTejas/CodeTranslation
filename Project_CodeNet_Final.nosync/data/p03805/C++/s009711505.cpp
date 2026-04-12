#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M,a,b;
  cin >> N >> M;
  vector<vector<bool>> ab(N,vector<bool>(N));
  while (M--) {
    cin >> a >> b;
    ab[--a][--b] = true;
    ab[b][a] = true;
  }
  int answer = 0, x[N];
  for (int i = 0; i < N; i++) {
    x[i] = i;
  }
  do {
    bool valid = true;
    for (int i = 1; i < N; i++) {
      if (!ab[x[i]][x[i-1]]) {
        valid = false;
      }
    }
    answer += valid;
  } while (next_permutation(x+1,x+N));
  cout << answer;
}