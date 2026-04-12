#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
using namespace std;


void solve(){
  int x, y, z; cin >> x >> y >> z;
  x -= z;
  cout << x / (y + z) << endl;
  return;
}

int main(){
  solve();
  return 0;
}
