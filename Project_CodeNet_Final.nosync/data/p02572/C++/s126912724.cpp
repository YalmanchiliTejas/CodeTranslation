#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  int mod = 1000000007;
  int n;
  cin >> n;
  ll sum = 0, ans = 0;

  rep(i, n) {
    int a;
    cin >> a;
    ans = (ans + a * sum) % mod;
    sum = (sum + a) % mod;
  }

  cout << ans << endl;

  return 0;
}
/*
*/
