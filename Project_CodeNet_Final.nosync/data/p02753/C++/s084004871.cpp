#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  char c[3]; rep(i, 3) cin >> c[i];
  int s = 0;
  rep(i, 3) s += c[i] - 'A';
  if (s == 0 || s == 3) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}