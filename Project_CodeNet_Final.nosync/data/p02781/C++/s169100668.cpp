#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <climits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define revrep(i, n) for(ll i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define chmin(x, y) x = min(x, y);
#define chmax(x, y) x = max(x, y);

//const ll INFL = LLONG_MAX;//10^18 = 2^60
const ll INFL = 1LL<<60;
//const int INF = INT_MAX;
const ll INF = 1 << 30;//10^9
//ll MOD = 1000000007;
ll MOD = 998244353;

vector<ll> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};

void pres(double A, ll x = 20){cout << fixed << setprecision(x) << A << endl;}
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}
//ll cnt_bit(ll x){return __builtin_popcountll(x);}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x; k /= 2;
  }
  return res;
}

ll pow_mod(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}

ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){
  ll res = x / gcd(x, y);
  res *= y;
  return res;
};


string S;
ll K;
ll dp[110][2][4];
void solve(){
  cin >> S >> K;
  dp[0][0][0] = 1;
  rep(i, S.size())rep(j ,2)rep(k, 4){
    //0が出る
    if(S[i] - '0' == 0) dp[i+1][j][k] += dp[i][j][k];
    else dp[i+1][1][k] += dp[i][j][k];
    //0以外が出る
    for(ll l = 1; l <= 9; l++){
      if(l > S[i] - '0'){
        if(j == 0) continue;
        if(k == 3) continue;
        dp[i+1][j][k+1] += dp[i][j][k];
      }else if(l == S[i] - '0'){
        if(k == 3) continue;
        dp[i+1][j][k+1] += dp[i][j][k];
      }else{
        if(k == 3) continue;
        dp[i+1][1][k+1] += dp[i][j][k];
      }
    }
  }
  cout << dp[S.size()][0][K] + dp[S.size()][1][K] << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
