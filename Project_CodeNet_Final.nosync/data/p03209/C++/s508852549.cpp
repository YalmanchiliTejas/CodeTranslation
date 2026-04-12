#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;

ll n;
ll k;
ll pa[100];
ll al[100];

ll solve(ll l, ll x) {
  if(l == 0) return 1;
  if(x == 1) return 0;
  if(x <= 1 + al[l-1]) return solve(l-1, x-1);
  if(x == 2 + al[l-1]) return 1 + solve(l-1, x-1);
  else return pa[l-1] + 1 + solve(l-1, x-al[l-1]-2);
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>k;
  pa[0] = 1;
  FOR(i, 1, n + 1) {
    pa[i] = pa[i-1] * 2 + 1;
  }
  al[0] = 1;
  FOR(i, 1, n + 1) {
    al[i] = al[i-1] * 2 + 3;
  }
  cout << solve(n, k) << endl;
  
  return 0;

}
