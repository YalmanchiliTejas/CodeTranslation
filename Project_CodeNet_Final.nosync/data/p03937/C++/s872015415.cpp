#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int ans = 0;
  cin >> a >> b;
  vector<char> vec(a * b);
  for (int i = 0; i < a * b; i++) {
    cin >> vec.at(i);
    if (vec.at(i) == '#') ans++;
  }
  if (ans == a + b - 1) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}