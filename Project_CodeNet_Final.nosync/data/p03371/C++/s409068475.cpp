#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
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
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
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



int main(void) {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  if (a + b < 2 * c) {
	ans = a * x + b * y;
  }
  else {
	if (x > y) {
	  ans += y * 2 * c;
	  if (a < 2 * c) {
		ans += llabs(x - y)*a;
	  }
	  else {
		ans += llabs(x - y)*c * 2;
	  }
	}
	else {
	  ans += x * 2 * c;
	  if (b < 2 * c) {
		ans += llabs(x - y)*b;
	  }
	  else {
		ans += llabs(x - y)*c * 2;
	  }
	}
  }
  
  cout << ans << endl;

  return 0;
}