#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int X;
  cin >> X;
  string res;
  if (X >= 30) {
    res = "Yes";
  } else {
    res = "No";
  }
  cout << res << endl;
  return 0;
}
