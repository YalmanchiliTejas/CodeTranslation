#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  dump((10*g+b)%4 == 0 ? "YES" : "NO");
  return 0;
}
