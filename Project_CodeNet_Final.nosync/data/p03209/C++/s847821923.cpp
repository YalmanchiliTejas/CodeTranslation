#include <bits/stdc++.h>
using namespace std;

long long n, x;
long long all[51], p[51];

long long calc(long long level, long long k) {
  if (level == 0 || k == 0) {
    return k;
  }
  if (k == all[level-1] * 2 + 3) {
    return p[level-1] * 2 + 1;
  } else if (k > all[level-1] + 2) {
    return p[level-1] + calc(level-1, k - all[level-1] - 2) + 1;
  } else if (k == all[level-1] + 2) {
    return p[level-1] + 1;
  } else {
    return calc(level-1, k-1);
  }
}
int main() {
  cin>>n>>x;
  all[0] = 1;
  p[0] = 1;
  for (int i=1; i<n; i++) {
    all[i] = all[i-1] * 2 + 3;
    p[i] = p[i-1] * 2 + 1;
  }
  cout<<calc(n, x)<<endl;
}