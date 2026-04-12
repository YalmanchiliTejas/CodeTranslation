#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
  ll x;
  cin >> x;

  string ans;
  if (x >= 30) {
    ans = "Yes";
  } else {
    ans = "No";
  }
  cout << ans << endl;
  return 0;
}