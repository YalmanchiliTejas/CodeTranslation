#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << endl
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> V;

int main() {
  int n;
  cin >> n;
  int x, y;
  x = y = 0;
  x = 800*n;
  y = n/15;
  y *= 200;
  dump(x-y);
  return 0;
}
