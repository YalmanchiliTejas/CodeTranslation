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
  vecint a(n);
  REP(i,n)cin>>a[i];
  multiset<int> s;
  s.insert(a[0]);
  int cnt=0;
  FOR(i,1,n) {
    auto itr = s.lower_bound(a[i]);
    if (itr != s.begin()) {
      --itr;
      ++cnt;
      s.erase(itr);
    }
    s.insert(a[i]);
  }
  cout<<n-cnt<<endl;
  return 0;
}
