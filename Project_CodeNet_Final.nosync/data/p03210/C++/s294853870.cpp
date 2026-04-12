#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
 
using namespace std;
using i64=long long int;
 
int main() {
  int X;
  cin >> X;
  
  if (X == 3 || X == 5 || X == 7) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  
  return 0;
}