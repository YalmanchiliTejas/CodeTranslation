#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x, y, m; //mは剰余
  cin >> n;
  x = n * 800;
  m = n % 15;
  y = (n - m) / 15 * 200;
    cout << (x - y);
}