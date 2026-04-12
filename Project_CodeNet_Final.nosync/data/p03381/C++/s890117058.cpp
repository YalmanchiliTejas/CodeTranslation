#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n;
  cin>>n;
  vecint v(n);
  REP(i,n) cin>>v[i];
  vecint a = v;
  sort(ALL(a));
  REP(i,n) {
    int idx = lower_bound(ALL(a), v[i]) - begin(a);
    if (idx < n/2) {
      cout << a[n/2] << endl;
    } else {
      cout << a[n/2-1] << endl;
    }
  }
  return 0;
}
