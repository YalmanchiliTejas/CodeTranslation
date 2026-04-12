#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; i++)
#define MOD 1e9+7
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int sum = y + 2 * z;
  int ans = 1;
  while(true) {
    sum += y + z;
    if (sum > x) break;
    else ans++;
  }
  cout << ans << endl;
}