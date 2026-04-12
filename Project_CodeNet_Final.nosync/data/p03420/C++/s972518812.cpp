#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;

int get(int x) {
  int pos = n / x, yu = n % x;
  if(yu >= m) yu = yu - m + 1;
  else yu = 0;
  return pos * (x - m) + yu;
}

int main() {
  cin >> n >> m;
  if(!m) printf("%lld\n", 1ll * n * n);
  else {
    ll ans = 0;
    for(int i = m + 1; i <= n; ++i) {
     // printf("%d\n", get(i));
      ans += get(i);
    }
    printf("%lld\n", ans);
  }
  return 0;
}