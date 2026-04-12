#include <bits/stdc++.h>
using namespace std;

// 1s = 10 ^ 8 loop

int main() {
  int X;
  cin >> X;
  
  bool r = false;
  vector<int> v = {7, 5, 3};
  if (find(v.begin(), v.end(), X) != v.end()) {
    r = true;
  }

  cout << (r ? "YES" : "NO") << endl;
}
