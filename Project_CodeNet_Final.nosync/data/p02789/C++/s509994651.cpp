#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  string ans = "Yes";
  if (n != m) {
    ans = "No";
  }

  cout << ans << endl;

  return 0;
}