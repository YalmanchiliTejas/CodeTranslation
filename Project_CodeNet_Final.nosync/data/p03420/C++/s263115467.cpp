#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin>>n>>k;

  if (k == 0) {
    cout<<n*n<<endl;
    return 0;
  }
  long long ans = 0;
  for (int b=k+1; b<=n; b++) {
    int c = n % b;
    if (c >= k) {
      ans += (n - c) / b * (c - k + 1) + ((n - c) / b - 1) * (b - 1 - c) + b - k;
    } else {
      ans += (n - k) / b * (b - k) + b - k;
    }
  }
  cout<<ans<<endl;
}