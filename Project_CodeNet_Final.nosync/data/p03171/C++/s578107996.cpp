#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cassert>
#include <string>
#include <cstring>
#include <bitset>
 
#define FOR(i, a, b) for(int i = a; i < (int) b; i++)
#define F0R(i, a) FOR (i, 0, a)
#define ROF(i, a, b) for(int i = a; i >= (int) b; i--)
#define R0F(i, a) ROF(i, a, 0)
#define GO(i, a) for (auto i : a)
 
#define rsz resize
#define eb emplace_back
#define pb push_back
#define sz(x) (int) x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define f first
#define s second
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vpii> vvpii;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef vector<pi64> vpi64;

const int dr[] = {+1, -1, +0, +0, +1, -1, +1, -1};
const int dc[] = {+0, +0, +1, -1, +1, -1, -1, +1};
const int ms[] = {+31, +29, +31, 30, +31, +30, +31, +31, +30, +31, +30, +31};

const int N = 3e3 + 5;

int n, a [N];

i64 dp [N][N][2];

i64 solve (int left, int right, int who) {
  if (left > right) return 0;
  i64 &res = dp[left][right][who];
  if (~res) return res;
  if (who == 0) {
    res = -1e18;
    res = max (res, solve (left + 1, right, who ^ 1) + a[left]);
    res = max (res, solve (left, right - 1, who ^ 1) + a[right]);
  } else {
    res = 1e18;
    res = min (res, solve (left + 1, right, who ^ 1) - a[left]);
    res = min (res, solve (left, right - 1, who ^ 1) - a[right]);
  }
  return res;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  F0R (i, n) cin >> a[i];
  memset (dp, -1, sizeof(dp));
  cout << solve (0, n - 1, 0) << '\n';
  return 0;
}
