#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int x;
  cin >> x;
  bool flag = false;
  for(int i = 3; i <= 7; i += 2) {
    if(x == i) flag = true;
  }
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;
}