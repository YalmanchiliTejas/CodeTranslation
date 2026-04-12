#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;
int main() {
  int n;
  int ans = 1;
  cin >> n;
  vector<int> l(n);
  for(int i = 0; i < n;i++) cin >> l[i];
  int m = l[0];
  for(int i = 1; i < n; i++) {
    if(l[i] >= m) ans += 1;
    m = max(l[i], m);
  }
  cout << ans << endl;
}