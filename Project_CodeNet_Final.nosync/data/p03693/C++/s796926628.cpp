#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (stoi(to_string(b) + to_string(c)) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}