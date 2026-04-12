#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> V(9, vector<int>(9));
  for (int i = 0, a, b; i < M && cin >> a >> b; i++) V.at(a).at(b)++, V.at(b).at(a)++;
  vector<int> P(N);
  for (int i = 0; i < N; i++) P.at(i) = i + 1;
  int ans = 0;
  do {
    for (int i = 0; i + 1 < N; i++) if (!V.at(P.at(i)). at(P.at(i + 1))) goto NG;
    ans++;
    NG:;
  } while (next_permutation(P.begin(), P.end()) && P.at(0) == 1);

  cout << ans << endl;  
}