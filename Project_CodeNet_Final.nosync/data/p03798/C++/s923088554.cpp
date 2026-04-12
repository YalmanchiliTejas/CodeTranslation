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
#define PB(a,num) FOR(i,0,num) {ll x; scanf("%lld",&x); a.pb(x); }
#define LOWER(a,x) lower_bound(ALL(a), x) - a.begin() - 1;
#define COUNT(a,x)  upper_bound(ALL(a), x) - lower_bound(ALL(a), x);
#define MCOUNT(a,x,y) upper_bound(ALL(a), y) - lower_bound(ALL(a), x);
#define INF 111111111111111111
#define MOD 1000000007
#define pb push_back
#define F first
#define S second
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
ll n = 0, m = 0, ans = 0, sum = 0, cnt = 0, tmp = 0, ma = 0, mi = 0;
string s;
bool flag, ok;
ll dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
ll ddx[8] = { 1,-1,0,0,1,1,-1,-1 }, ddy[8] = { 0,0,1,-1,1,-1,1,-1 };
#pragma endregion
#define MAX 111111

string a[4], b;

char SW(char c1,char c2,char info) {
  if (info == 'o') {
	if (c2 == 'S') {
	  if (c1 == 'S') {
		return 'S';
	  }
	  else {
		return 'W';
	  }
	}
	else {
	  if (c1 == 'S') {
		return 'W';
	  }
	  else {
		return 'S';
	  }
	}
  }
  else {
	if (c2 == 'S') {
	  if (c1 == 'S') {
		return 'W';
	  }
	  else {
		return 'S';
	  }
	}
	else {
	  if (c1 == 'S') {
		return 'S';
	  }
	  else {
		return 'W';
	  }
	}
  }
}

bool solve(ll x) {
  FOR(i, 3, n) {
	a[x] += SW(a[x][i - 2], a[x][i - 1], b[i - 1]);
  }
  if ((a[x][0] == SW(a[x][n - 2], a[x][n - 1], b[n - 1])) && (a[x][1] == SW(a[x][n - 1], a[x][0], b[0]))) {
	return true;
  }
  else {
	return false;
  }
}

int main(void) {
  cin >> n;
  cin >> b;

  if (b[1] == 'o') {
	a[0] = "SSS";
	a[1] = "WSW";
	a[2] = "WWS";
	a[3] = "SWW";
  }
  else {
	a[0] = "WSS";
	a[1] = "SSW";
	a[2] = "SWS";
	a[3] = "WWW";
  }

  FOR(i, 0, 4) {
	if (solve(i)) {
	  cout << a[i] << endl;
	  return 0;
	}
  }
  cout << "-1" << endl;

  return 0;
}