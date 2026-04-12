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
  vector<ll> s(n);
  REP(i,n)cin>>s[i];
  ll mx = 0;
  FOR(step,1,n-1) {
    ll sum = 0;
    set<int> a;
    for (int j = 1; (j+1)*step < n-1; ++j) {
      if (j*step*2 == n-1) break;
      if (a.count(n-1-j*step)) break;
      sum += s[j*step] + s[n-1-j*step];
      a.insert(j*step);
      mx = max(mx, sum);
    }
  }
  cout<<mx<<endl;
  return 0;
}
