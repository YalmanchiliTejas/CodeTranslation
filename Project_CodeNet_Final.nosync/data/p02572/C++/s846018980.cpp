#include <bits/stdc++.h>

#define F first
#define S second
#define ll long long
#define pb push_back
#define endl '\n'

using namespace std;

const int MOD = 1e9+7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  ll sum = 0, ans = 0;
  for (int &i: v) {
    cin >> i;
    sum = (sum + i) % MOD; 
  }
  for (int i = 0; i < n; ++i) {
    sum -= v[i];
    if (sum < 0) sum += MOD;
    ans += v[i] * sum;
    ans %= MOD;
  }           
  cout << ans << endl;
}
