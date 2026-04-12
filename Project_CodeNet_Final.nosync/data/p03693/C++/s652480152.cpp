#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(){
  int a, b, c; cin >> a >> b >> c;
  int ans = 100 * a + 10 * b + c;
  if(ans % 4 == 0) cout << "YES\n";
  else cout << "NO\n";
  return;
}

int main(){
  solve();
  return 0;
}
