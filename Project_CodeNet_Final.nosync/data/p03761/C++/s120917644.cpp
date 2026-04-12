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
#define LOWER(a,x) lower_bound(ALL(a), x) - a.begin() - 1;
#define COUNT(a,x)  upper_bound(ALL(a), x) - lower_bound(ALL(a), x);
#define MCOUNT(a,x,y) upper_bound(ALL(a), y) - lower_bound(ALL(a), x);
#define scan(x) scanf("%lld",&x);
#define inf 5555555555555555555
#define mod 1000000007
#define pi 3.14159265358979323846
#define pb push_back
#define F first
#define S second
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef map<ll, ll> MAP;
typedef set<ll> SET;
ll n = 0, m = 0, ans = 0, sum = 0, cnt = 0, tmp = 0, ma = 0, mi = 0;
string s;
bool flag, ok;
ll dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
ll ddx[9] = { 1,-1,0,0,1,1,-1,-1,0 }, ddy[9] = { 0,0,1,-1,1,-1,1,-1,0 };
#pragma endregion
#define MAX 111111



int main(void) {
  map<char, ll> mp[55];

  cin >> n;
  cin >> s;
  FOR(i, 0, s.length()) mp[0][s[i]]++;

  FOR(i, 1, n) {
	cin >> s;
	FOR(j, 0, s.length()) mp[i][s[j]]++;
	for (char c = 'a';c <= 'z';c++) {
	  mp[i][c] = min(mp[i - 1][c], mp[i][c]);
	}
  }

  for (auto it : mp[n-1]) {
	FOR(i, 0, it.second) cout << it.first;
  }
  cout << endl;

  return 0;
}