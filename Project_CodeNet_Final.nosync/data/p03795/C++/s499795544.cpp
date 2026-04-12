#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int n;
  cin >> n;
  int x = n*800;
  int y = n/15*200;
  int ans = x-y;
  cout << ans << endl;
}