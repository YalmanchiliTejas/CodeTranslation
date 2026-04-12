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
  vecint v(n, -1);
  REP(i,n) {
    int a;
    cin>>a;
    *prev(lower_bound(ALL(v),a))=a;
  }
  cout<<n-count(ALL(v),-1)<<endl;
  return 0;
}
