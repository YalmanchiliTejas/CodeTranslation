#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int r, g, b;
  cin >> r >> g >> b;
  int a = g * 10 + b;
  if(a % 4 == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}