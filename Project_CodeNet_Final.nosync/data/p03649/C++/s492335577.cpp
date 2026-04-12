#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin>>n;
  long long a[n];
  for (int i=0; i<n; i++) cin>>a[i];

  long long ans = 0;
  while (true) {
    sort(a, a + n);
    if (a[n-1] < n) {
      break;
    }
    long long cnt = (a[n-1] -  n) / n + 1;
    ans += cnt;
    a[n-1] -= cnt * n;
    bool ok = true;
    for (int i=0; i<n-1; i++) {
      a[i] += cnt;
    }
  }
  cout<<ans<<endl;
}