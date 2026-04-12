#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <vector>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);


int main (int argc, char **argv) {
  int x, y, z;
  std::cin >> x >> y >> z;
   
  for (int i=1;;i++) {
    if (i*y + (i+1)*z > x) {
      std::cout << (i-1) << std::endl;
      break;
    }
  }	  
  return 0;
}
