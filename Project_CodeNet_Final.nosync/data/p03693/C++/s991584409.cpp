#include <bits/stdc++.h>
using namespace std;

int main() {
  string R, G, B;
  cin >> R >> G >> B;

  string ans = R + G + B;

  cout << ((stoi(ans) % 4 == 0) ? "YES" : "NO") << endl;
}