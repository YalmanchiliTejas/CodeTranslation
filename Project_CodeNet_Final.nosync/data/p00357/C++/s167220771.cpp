#include <bits/stdc++.h>
#define int long long
#define double long double
#define INF 1e18
using namespace std;
int a[300100];
int d[300100];

signed main() {
  // DP???
  // probably not
  int N; cin >> N;
  
  for (int i = 0; i < N; i++) a[i] = 0;
  for (int i = 0; i < N; i++) {
    cin >> d[i];
    if (d[i]/10==0&&a[i]-1<=0) {
      cout << "no" << endl;
      return 0;
    } else {
      a[i+1] = max(d[i]/10,a[i]-1);
    }
  }

  for (int i = 0; i < N; i++) a[i] = 0;
  for (int i = N-1; i >= 0; i--) {
    if (d[i]/10==0&&a[i]-1<=0) {
      cout << "no" << endl;
      return 0;
    } else {
      a[i-1] = max(d[i]/10,a[i]-1);
    }
  }

  cout << "yes" << endl;
}

