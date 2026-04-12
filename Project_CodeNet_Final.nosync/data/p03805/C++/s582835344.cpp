#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<functional>
#include<set>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define LOWER(x,y) lower_bound(ALL(x), y) - x.begin() - 1;
#define INF 9223372036854775807
#define MOD 1000000007
#define pb push_back
#define F first 
#define S second
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, ans = 0, sum = 0, cnt = 0, tmp = 0;
string s;
bool flag;
#pragma endregion
#define MAX 111111



int main(void) {
  ll a, b;
  vll edge[10], path;
  cin >> n >> m;
  FOR(i, 2, n + 1) path.pb(i);
  FOR(i, 0, m) {
	cin >> a >> b;
	edge[a].pb(b);
	edge[b].pb(a);
  }

  do {
	cnt = 0; tmp = 1;
	FOR(i, 0, n - 1) {
	  flag = false;
	  FOR(j, 0, edge[tmp].size()) if (edge[tmp][j] == path[i]) flag = true;
	  if (!flag) break;
	  tmp = path[i];
	  cnt++;
	}
	if (cnt == n - 1) ans++;
  } while (next_permutation(ALL(path)));

  cout << ans << endl;

  return 0;
}