#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<numeric>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
#include<random>

#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0LL,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0LL,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define COUNT(a,y,x) upper_bound(all(a), y) - lower_bound(all(a), x)
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end())
#define pb push_back
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 2222222222222222222LL;
//const ll mod = 1000000007LL;
const ll mod = 998244353LL;

ll n = 0, m = 0, ans = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok;
ll dx[9] = { 0,1,0,-1,0,1,1,-1,-1 }, dy[9] = { 0,0,1,0,-1,1,-1,1,-1 };
#define endl '\n'
#pragma endregion
#define MAX 222222


ll a[MAX], memo[3333][3333];

ll dfs(ll le, ll ri) {
  ll cur = n - (ri - le);
  cur %= 2;
  if (le == ri) return cur ? a[le] : 0;
  if (memo[le][ri]) return memo[le][ri];
  if (cur) return memo[le][ri] = max(dfs(le + 1, ri) + a[le], dfs(le, ri - 1) + a[ri]);
  else return memo[le][ri] = min(dfs(le + 1, ri), dfs(le, ri - 1));
}


int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);


  cin >> n;
  rep(i, n) cin >> a[i];
  ll sum = accumulate(a, a + n, 0LL);
  cout << 2 * dfs(0, n - 1) - sum << endl;



  return 0;
}