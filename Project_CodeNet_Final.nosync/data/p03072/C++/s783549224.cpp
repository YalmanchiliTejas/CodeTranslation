#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; i++) cin >> h[i];
  int maxN = h[0], ans = 1;
  for (int i = 1; i < n; i++) {
    if (maxN <= h[i]) ans++;
    maxN = max(maxN, h[i]);
  }
  cout << ans << endl;
}