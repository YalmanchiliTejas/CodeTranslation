#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  bool mat[8][8] = {{}};

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    mat[a][b] = mat[b][a] = true;
  }

  vector< int > path(N);
  iota(begin(path), end(path), 0);
  int ret = 0;
  do {
    bool flag = true;
    for(int i = 1; i < path.size(); i++) flag &= mat[path[i - 1]][path[i]];
    ret += flag;
  } while(next_permutation(begin(path) + 1, end(path)));

  cout << ret << endl;
}