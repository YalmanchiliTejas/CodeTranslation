#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
int a[100];
signed main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i <= a[0]; i++) {
    int jobs = 0;
    for (int j = 0; j < N; j++) {
      jobs += a[j];
      jobs -= i;
      if (jobs<0) break;
    }
    if (jobs >= 0) ans = i;
  }
  cout << ans << endl;
}

