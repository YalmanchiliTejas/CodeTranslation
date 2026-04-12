#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
// << fixed << setprecision
// --------------------------------------
ll n, x, m;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> x >> m;

  ll ans = x;

  vector<ll> memo(m + 1, -1);
  vector<ll> sum;
  sum.push_back(0);
  sum.push_back(x);
  memo[x] = 1;
  ll xx = x;
  REP(i, min(n - 1, m + 10)) {
    xx = xx * xx % m;
    if(memo[xx] != -1) {
      ans += xx;
      sum.push_back(ans);
      ans += ((n - (i + 2)) / (i + 2 - memo[xx])) * (sum[i + 2] - sum[memo[xx]]);
      ans += sum[memo[xx] + ((n - (i + 2)) % (i + 2 - memo[xx]))] - sum[memo[xx]];
      break;
    } else {
      ans += xx;
      sum.push_back(ans);
      memo[xx] = i + 2;
    }
  }

  cout << ans << endl;
}
