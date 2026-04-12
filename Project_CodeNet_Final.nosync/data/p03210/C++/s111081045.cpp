#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;

int main() {
  ll X;
  cin >> X;
  
  if (X == 3 || X == 5 || X == 7) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}