#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <bitset>

#define REP(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define FILL(x, y) memset(x, y, sizeof(x))
#define pb push_back
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

template<class T>bool chmax(T &a, const T &b) {
   if (a < b) {
      a = b;
      return 1;
   }
   return 0;
}
template<class T>bool chmin(T &a, const T &b) {
   if (a > b) {
      a = b;
      return 1;
   }
   return 0;
}

using namespace std;
using ll = long long;

const int kInf = 1e9;
const ll kLInf = 1e18;

int gcd (int a, int b) {
   return b ? gcd(b, a % b) : a;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N;
int a[3010];
ll dp[3010][3010];
bool flg[3010][3010];

ll REC(int l, int r);

int main()
{
   cin >> N;
   REP(i, N) {
      cin >> a[i];
   }
   cout << REC(0, N-1) << endl;
   return 0;
}

ll REC(int l, int r)
{
   if (flg[l][r]) return dp[l][r];
   flg[l][r] = 1;
   if (l==r) {
      eprintf("dp[%d][%d] = %d\n", l, r, a[l]);
      return dp[l][r] = a[l];
   }
   ll left = a[l] - REC(l+1, r);
   ll right = a[r] - REC(l, r-1);
   eprintf("dp[%d][%d] = %d\n", l, r, max(left, right));
   return dp[l][r] = max(left, right);
}
   
