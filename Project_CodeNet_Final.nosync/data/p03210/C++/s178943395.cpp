#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x; cin >> x;
  if (x == 3 || x == 5 || x == 7) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}