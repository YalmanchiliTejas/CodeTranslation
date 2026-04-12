#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <cmath>
#include <map>
using ll = long long;
using namespace std;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  cout << ( (100*r+10*g+b) % 4 == 0 ? "YES" : "NO" ) << endl;
}
