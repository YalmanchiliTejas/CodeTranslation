#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<vector<bool>> table(N, vector<bool>(N, false)); //trueなら道あり
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    table[a-1][b-1] = true;
    table[b-1][a-1] = true;
  }

  vector<int> v(N); //1~N
  for (int i = 0; i < N; i++) {
    v[i] = i;
  } //sort済み

  int cnt = 0;
  do {
    if (v[0] != 0) {
      break;
    }
    bool flag = true;
    for (int i = 0; i < N - 1; i++) {
      if (!table[v[i]][v[i+1]]) {
        flag = false;
        break;
      }
    }

    if (flag) cnt++;
  } while (next_permutation(v.begin(), v.end()));

  cout << cnt << endl;
}

