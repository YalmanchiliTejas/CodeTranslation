#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 1e5+23;

int a[N];

void solve() {
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int left = a[0], right = a[0];
  long long sum = 0;
  for (int i = 1, j = n-1, left = a[0], right = a[0];;) {
    sum += abs(a[j]-left);
    left = a[j--];
    if (i > j) break;
    sum += abs(a[j]-right);
    right = a[j--];
    if (i > j) break;
    sum += abs(a[i]-left);
    left = a[i++];
    if (i > j) break;
    sum += abs(a[i]-right);
    right = a[i++];
    if (i > j) break;
  }
  long long ans = sum; sum = 0;
  for (int i = 0, j = n-2, left = a[n-1], right = a[n-1];;) {
    sum += abs(a[i]-left);
    left = a[i++];
    if (i > j) break;
    sum += abs(a[i]-right);
    right = a[i++];
    if (i > j) break;
    sum += abs(a[j]-left);
    left = a[j--];
    if (i > j) break;
    sum += abs(a[j]-right);
    right = a[j--];
    if (i > j) break;
  }
  printf("%lld", max(sum, ans));
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
