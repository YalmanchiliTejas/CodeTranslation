#include <iostream>

using namespace std;

#define int long long

const int N = 2e5 + 10;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);    
  int x;
  cin >> x;
  if (x >= 30) cout << "Yes";
  else cout << "No";
  return 0;
}