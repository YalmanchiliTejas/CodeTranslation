#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n, k;
  cin>>n>>k;
  int64_t count = 0;
  if (k == 0) {
    cout << (int64_t)n * n << endl;
    return 0;
  }
  FOR(i,k,n+1) {
    count += (n/i) * (i-k);
    count += max(0, n%i+1 - k);
  }
  cout << count << endl;
  return 0;
}
