#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<ll(n); i++)
#define REPR(i, n) for(ll i=n-1; i>=0; i--)
#define FOR(i, m, n) for(ll i=m; i<ll(n); i++)
#define ALL(v) v.begin(), v.end()
#define SIZE(x) ll(x.size()) 
using P = pair<int, int>;
const int INF = 2e9;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x; cin >> x;
  cout << (x>=30 ? "Yes\n" : "No\n");

  return 0;
}
