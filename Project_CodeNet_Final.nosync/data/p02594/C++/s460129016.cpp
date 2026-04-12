/*input
30
*/

#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 4;

char s[N];
int cnt[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int x; cin >> x;
  cout << ((x < 30) ? "No" : "Yes") << endl;

  return 0;
}