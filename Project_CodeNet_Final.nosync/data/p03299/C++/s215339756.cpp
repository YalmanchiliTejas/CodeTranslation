#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
  #define debug(...) printf(__VA_ARGS__)
#else
  #define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MOD = 1e9 + 7;

int add(int x, int y) { x += y; if (x >= MOD) x -= MOD; return x; }
int sub(int x, int y) { x -= y; if (x < 0) x += MOD; return x; }
int mul(int x, int y) { return 1ll * x * y % MOD; }

int pw(int a, int k) {
  int res = 1;
  while (k) {
    if (k % 2 == 1)
      res = mul(res, a);
    a = mul(a, a);
    k /= 2;
  }
  return res;
}

const int MAXN = 100 + 10;
int N;
int h[MAXN];
VI nums;

int dp[MAXN][MAXN];
int f(int x, int y) {
  if (dp[x][y] >= 0)
    return dp[x][y];
  assert(x >= 1 && y >= 0 && y <= h[x]);
  if (x == 1) {
    dp[x][y] = pw(2, nums[h[x]] - nums[y]);
    if (y > 0)
      dp[x][y] = mul(2, dp[x][y]);
    debug("dp[%d][%d(%d)] = %d\n", x, y, nums[y], dp[x][y]);
    return dp[x][y];
  }
  int t1 =  mul(f(x - 1, min(y, h[x - 1])), pw(2, max(0, min(nums[h[x]] - nums[y], nums[h[x]] - nums[h[x - 1]]))));
  int t2 =  mul(f(x - 1, min(h[x], h[x - 1])), pw(2, max(0, min(nums[h[x]] - nums[y], nums[h[x]] - nums[h[x - 1]]))));
  dp[x][y] = add(t1, t2);
  debug("dp[%d][%d(%d)] = %d\n", x, y, nums[y], dp[x][y]);
  return dp[x][y];
}

int main() {
  memset(dp, -1, sizeof(dp));
  cin >> N;
  nums.PB(0);
  for (int i = 1; i <= N; i++) {
    cin >> h[i];
    nums.PB(h[i]);
  }
  sort(ALL(nums));
  nums.resize(unique(ALL(nums)) - begin(nums));
  for (int i = 1; i <= N; i++)
    h[i] = lower_bound(ALL(nums), h[i]) - begin(nums);
  cout << f(N, 0) << endl;
  return 0;
}
