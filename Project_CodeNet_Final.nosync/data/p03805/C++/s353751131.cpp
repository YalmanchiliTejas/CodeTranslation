#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int main () {
  int N, M;
  cin >> N >> M;
  vector<int>num(N - 1);
  for (int i = 0; i < N - 1; i ++) num[i] = i + 2;
  bool load[10][10];
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= N; j ++) {
      load[i][j] = false;
    }
  }
  for (int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    load[a][b] = load[b][a] = true;
  }
  int ans = 0;
  do {
    bool ok = true;
    for (int i = 0; i < N - 1; i ++) {
      int p = 1;
      int n = num[i];
      if (i > 0) p = num[i - 1];
      if (!load[p][n]) ok = false;
    }
    if (ok) ans ++;
  }while(next_permutation(num.begin(), num.end()));
  cout << ans << endl;
}


