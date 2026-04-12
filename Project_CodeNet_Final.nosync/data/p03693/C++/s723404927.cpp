#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int a, b, c;
  cin >> a >> b >> c;

  if ((a * 100 + b * 10 + c) % 4 == 0) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
