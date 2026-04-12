#include <bits/stdc++.h>
using namespace std;

int main(int, char**) {
  int a[20], n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  
  int ans = 1;
  int maxh = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] >= maxh) {
      maxh = a[i];
      ans++;
    }
  }
  cout << ans << endl;
}