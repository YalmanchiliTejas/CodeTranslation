#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define space ' '

inline void init() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

int main(void) {
  int r, g, b;
  cin >> r >> g >> b;
  r = r * 100 + g * 10 + b;
  if (r % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl; 
  return 0;
}
