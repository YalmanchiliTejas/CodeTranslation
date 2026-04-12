#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MAX_N 1e5+10

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vbl;

int main() {
  int n;
  cin >> n;
  ll a[n];
  ll dpT[n][n], dpJ[n][n];
  for (int i = 0 ; i < n ; i++) {
    cin >> a[i];
    dpT[i][0] = a[i];
    dpJ[i][0] = -a[i];
  }

  for (int k = 1 ; k < n ; k++) {
    for (int i = 0 ; i+k < n ; i++) {
      dpT[i][k] = max(a[i]+dpJ[i+1][k-1],a[i+k]+dpJ[i][k-1]);
      dpJ[i][k] = min(dpT[i+1][k-1]-a[i],dpT[i][k-1]-a[i+k]);
    }
  }

  cout << dpT[0][n-1] << endl;

  return 0;
}