#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define REP(i,n) FOR(i,0,n)
 
int main() {
  int n; cin >> n;
  vector<int> x(n);
  vector<int> c(n);
  REP(i,n) cin >> x[i];
  REP(i,n) c[i] = x[i];
  sort(x.begin(), x.end());
  int l = x[n/2-1], r = x[n/2];
  REP(i,n) {
    if (c[i] < l) cout << r << endl;
    else if (c[i] > r) cout << l << endl;
    else if (c[i] == l) cout << r << endl;
    else if (c[i] == r) cout << l << endl;
  }
  return 0;
}