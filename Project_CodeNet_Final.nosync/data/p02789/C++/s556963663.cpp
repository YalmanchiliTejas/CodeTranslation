#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);

  int N,M; cin>>N>>M;
  bool ans = N == M;
  cout << (ans ? "Yes" : "No") << endl;

  return 0;
}
