#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define IN_LL(v) ll v;cin>>v;
#define IN(v) int v;cin>>v;
#define OUT(v) cout<<v<<endl

ll solve(int level, ll x) {
  if (level == 0)
    return x >= 1 ? 1 : 0;

  ll burger_size = 1;
  REP(i, level+2)
    burger_size *= 2;
  burger_size -= 3;

  ll patty = (burger_size + 1) / 2;

  if (x == burger_size / 2 + 1)
    return patty / 2 + 1;
  if (x > burger_size / 2 + 1)
    return (patty / 2 + 1) + solve(level - 1, x - (burger_size / 2 + 1));
  return solve(level - 1, x - 1);
}
int main() {
  IN(N); IN_LL(X);

  OUT(solve(N, X));
  return 0;
}
