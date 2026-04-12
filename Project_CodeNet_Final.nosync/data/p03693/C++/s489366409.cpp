#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define all(x) x.begin(), x.end()
#define rep(n) for (int i=0; i<n; ++i)

using namespace std;

int main(void){
  int r, g, b;
  cin >> r >> g >> b;
  int concat = 100*r + 10*g + b;
  if (concat % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}