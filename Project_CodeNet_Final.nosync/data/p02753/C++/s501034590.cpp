#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const string ln = "\n";
constexpr int INF = 1001001001;
constexpr int MOD = 1000000007;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  bool a = false;
  bool b = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      a = 1;
    } else {
      b = 1;
    }
  }

  if (a && b) {
    cout << "Yes" << ln;
  } else {
    cout << "No" << ln;
  }

  return 0;
}