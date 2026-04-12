#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> VI;
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<endl


int main() {
  IN(N);

  VI A(N), dp;
  cin >> A[0];
  dp.PB(-A[0]);

  REP(i, N-1) {
    IN(a);
    A.PB(a);
    auto it = upper_bound(ALL(dp), -a);
    if (it == dp.end())
        dp.PB(-a);
    else
        *it = -a;
  }
  OUT(dp.size());

  return 0;
}
