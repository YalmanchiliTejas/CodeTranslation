#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
 
using namespace std;
 
int main(void) {
  int N, M, ans = 0;
  cin >> N >> M;
  vector<vector<bool> > g(N, vector<bool>(N, false));
 
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    g[a - 1][b - 1] = g[b - 1][a - 1] = 1;
  }
 
  vector<int> v(N);
  iota(v.begin(), v.end(), 1);
 
  do {
    //始点が1でない時
    if (v[0] != 1)
      continue;
 
    bool flag = true;
    for (int i = 1; i < N; i++) {
      //通れるパスがなかった時
      if (!g[v[i - 1] - 1][v[i] - 1]) {
        flag = false;
        break;
      }
    }
 
    if (flag)
      ans++;
 
  } while (next_permutation(v.begin(), v.end()));
 
  cout << ans << endl;
  return 0;
}