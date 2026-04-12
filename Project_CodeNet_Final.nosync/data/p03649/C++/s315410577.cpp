#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 50;
 
int main() {
  int n;
  long long int a[N + 1];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  long long res= 0;
  bool find = true;
  while (find) {
    find = false;
    for (int i = 1; i <= n; ++i) {
      if (a[i] >= n) {
        find = true;
        long long g = a[i] / n;
        res += g;
        a[i] %= n;
        for (int j = 1; j <= n; ++j) {
          if (j != i) {
            a[j] += g;
          }
        }
      }
    }
  }
  printf ("%lld\n", res);
  return 0;
}