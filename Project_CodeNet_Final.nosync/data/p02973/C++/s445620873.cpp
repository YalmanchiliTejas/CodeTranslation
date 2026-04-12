#include <bits/stdc++.h>
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
using ll = long long;

int main(void)
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll &x:a) cin >> x;
  map<ll,ll> last;
  ll answer = 0;
  REP(i,n) {
    auto ite = last.lower_bound(a[i]);
    if(ite == last.begin()) ++answer;
    else {
      --ite;
      --(ite->second);
      if(ite->second == 0) last.erase(ite);
    }
    ++last[a[i]];
  }
  cout << answer << endl;
  return 0;
}
