#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int use = y + 2 * z;
  int num = 1;
  while (true) {
    use += y + z;
    num++;
    if (use > x) {
      num--;
      break;
    }
    if (use == x) break;
  }
  cout << num << endl;
}