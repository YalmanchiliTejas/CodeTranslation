#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define ff first
#define ss second
#define nl '\n'
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); srand(time(0));

  int n;
  cin >> n;
  pair<int,int> a[1+n];
  for(int i=1; i<=n; i++)
    cin >> a[i].ff, a[i].ss=i;
  sort(a+1, a+1+n);
  int ans[1+n];
  for(int i=1; i<=n; i++) {
    int lx = i-1, mid = n / 2;
    if( mid <= lx ) {
      ans[a[i].ss] = a[mid].ff;
    } else {
      ans[a[i].ss] = a[mid+1].ff;
    }
  }
  for(int i=1; i<=n; i++) cout << ans[i] << nl;

  return 0;
}
/* -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- -*- */
