#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;

  int G[10][100];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 100; j++) {
      G[i][j] = 0;
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    G[a][b] = 1;
    G[b][a] = 1;
  }
  vector<int> r_comb;
  for (int i = 1; i <= N; i++) {
    r_comb.emplace_back(i);
  }

  set<string> ans_set;
  do {
    int start = 1;
    int chk[M];
    for (int i = 1; i <= M; i++) {
      chk[i] = 0;
    }
    chk[start] = 1;

    string comb = to_string(start);
    for (auto itr = r_comb.begin() + 1; itr != r_comb.end(); itr++){
      if (G[start][*itr] == 1 && G[*itr][start] == 1 && chk[*itr] != 1) {
        chk[*itr] = 1;
        comb = comb + to_string(*itr);
        start = *itr;
      } else {
        start = 1;
        itr = r_comb.end();
        break;
      }
    }
    if ((int)comb.length() == N) {
      ans_set.insert(comb);
    }
  } while (next_permutation(r_comb.begin() + 1, r_comb.end()));
  cout << ans_set.size() << endl;
}
