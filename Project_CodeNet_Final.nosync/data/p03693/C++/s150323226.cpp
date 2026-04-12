#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int ans = r * 100 + g*10 + b;
  if(ans % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}