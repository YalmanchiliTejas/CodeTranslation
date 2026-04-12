#include<bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;

  bool ans = (x == 3) || (x == 5) || (x == 7);
  cout << (ans ? "YES" : "NO") << endl;
}
