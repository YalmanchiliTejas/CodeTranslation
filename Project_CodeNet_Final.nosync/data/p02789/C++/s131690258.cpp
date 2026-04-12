#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  int M; cin >> M;
  string ans = "No";
  if (M == N) ans = "Yes";
  cout << ans << '\n';
  return 0;
}