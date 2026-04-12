#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  set<pair<int, int>> S;
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    pair<int, int> p = make_pair(a, b);
    S.insert(p);
  }
  vector<int> A(N);
  for (int i = 0; i < N; i++) A.at(i) = i + 1;
  int ans = 0;
  do {
    if (A.at(0) != 1) break;
    bool X = true;
    for (int i = 1; i < N; i++) {
      pair<int, int> p = make_pair(A.at(i), A.at(i - 1));
      pair<int, int> q = make_pair(A.at(i - 1), A.at(i));
      if (!(S.count(p)) && !(S.count(q))) X = false;
    }
    if (X) ans++;
  } while(next_permutation(A.begin(), A.end()));
  cout << ans << endl;
}