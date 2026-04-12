#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, k;
  string s;
  cin >> n >> s >> k;
  for (int i = 0; i < n; i++) {
    if (s[i] != s[k - 1]) s[i] = '*';
  }
  cout << s << endl;
  return 0;
}