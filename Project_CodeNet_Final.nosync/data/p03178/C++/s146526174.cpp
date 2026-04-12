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
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;

ll n = 0, m = 0, ans = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok;
ll dx[9] = { 0,1,0,-1,0,1,1,-1,-1 }, dy[9] = { 0,0,1,0,-1,1,-1,1,-1 };
#define endl '\n'
#pragma endregion
#define MAX 222222


ll dp[MAX][2][111];



int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);


  cin >> s;
  cin >> m;
  dp[0][0][0] = 1;
  rep(i, s.length()) {
    ll digit = s[i] - '0';
    
    rep(j, digit) rep(k, m) {
      (dp[i + 1][1][(k + j) % m] += dp[i][0][k]) %= mod;
    }
    rep(j, 10) rep(k, m) {
      (dp[i + 1][1][(k + j) % m] += dp[i][1][k]) %= mod;
    }
    rep(k, m) (dp[i + 1][0][(k + digit) % m] += dp[i][0][k]) %= mod;
  }

  cout << (dp[s.length()][0][0] + dp[s.length()][1][0] + mod - 1) % mod << endl;


  return 0;
}