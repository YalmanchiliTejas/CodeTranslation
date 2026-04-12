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
  ll h, w;
  char c;
  cin >> h >> w;
  FOR(i, 0, h*w) {
	cin >> c;
	if (c == '#') cnt++;
  }
  if (cnt == h + w - 1) {
	cout << "Possible" << endl;
  }
  else {
	cout << "Impossible" << endl;
  }

  return 0;
}