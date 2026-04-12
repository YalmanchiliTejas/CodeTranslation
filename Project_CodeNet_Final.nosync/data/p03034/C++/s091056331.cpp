#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define RREP(i,n) for(int i = n - 1; i >= 0; i--)

#define ALL(v) v.begin(),v.end()
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define UNIQUE(v) do{sort(v.begin(), v.end()); v.erase( unique(v.begin(), v.end()), v.end() );} while(0)


#define y0 y3487465
#define y1 y8687969

#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

double EPS = 1e-9;
int INFi = 1000000005;
long long INFll = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
ll MOD = 1000000007;

ll N;
const int MAX_N = 200000;
ll s[MAX_N];

vector<int> divs(int n) {
  vector<int> res;
  for(int i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      res.push_back(i);
      if(i != 1 && i * i != n) {
        res.push_back(n / i);
      }
    }
  }
  return res;
}

int main(){
  cin >> N;
  REP(i, N) cin >> s[i];

  ll ans = 0;
  for(int c = 1; c < N - 1; c++) {
    ll dp[(N - 1) / c];
    dp[0] = 0;
    // cout << c << endl;
    REP(k, (N - 1) / c - 1) {
      ll a = N - 1 - (k + 1) * c;
      if(a <= c) break;
      if(a % c == 0 && a / c <= k + 1) break;
      dp[k + 1] = dp[k] + s[a] + s[(k + 1) * c];
      ans = max(ans, dp[k + 1]);

      // cout << dp[k + 1] << ",";
    }
    // cout << endl;
  }

  cout << ans << endl;

  return 0;
}
