#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<map>
#include<unordered_map>
#include<functional>
#include<set>
#include<numeric>

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
#define SUM(a) accumulate(all(a),0LL)
#define pb push_back
#define endl '\n'
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 2222222222222222222LL;
const ll mod = 1000000007LL;

ll n = 0, m = 0, ans = 0, cnt = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok = true, flag = false;
ll dx[9] = { 0,1,-1,0,0,1,1,-1,-1 }, dy[9] = { 0,0,0,1,-1,1,-1,1,-1 };
#pragma endregion
#define MAX 222222

pll dp[55];

void merge(ll lv) {
  if (dp[lv].first <= m && dp[lv].first) {
    m -= dp[lv].first;
    ans += dp[lv].second;
    return;
  }
  pll p = pll(m, ans);
  if (!m) return;
  if (m) m--;
  merge(lv - 1);
  if (m) {
    m--; ans++;
  }
  merge(lv - 1);
  if (m) m--;
  dp[lv].first = p.first - m;
  dp[lv].second = ans - p.second;
}


int main(void) {


  cin >> n >> m;
  dp[0].first = 1;
  dp[0].second = 1;
  merge(n);
  cout << ans << endl;


  return 0;
}