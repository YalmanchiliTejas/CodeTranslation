/**
 *    author:  tourist
 *    created: 17.11.2019 02:01:26       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i -= 2) cout << a[i] << " ";
  for (int i = n % 2; i < n; i += 2) cout << a[i] << " ";
  return 0;
}
