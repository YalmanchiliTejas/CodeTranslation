#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int n;
  scanf("%d", &n);
  int k = n / 15;
  int ans = 800 * n - 200 * k;
  printf("%d\n", ans);
	return 0;
}