#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans, m, k;
  cin >> n;
  cin >> m;
  n--;
  ans = 1;
  while (n--) {
    cin >> k;
    if (k >= m) {
      ans++; 
      m = k;
    }
  }
  printf("%d\n", ans);
  return 0;}
