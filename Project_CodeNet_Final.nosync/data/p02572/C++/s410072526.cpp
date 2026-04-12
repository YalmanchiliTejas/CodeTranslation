#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <list>
#include <climits>
#include <bitset>
#include <fstream>
#include <algorithm>
#include <functional>
#include <stack>
#include <string>
#include <cmath>
#define fi first
#define se second
#define re register
#define ls i << 1
#define rs i << 1 | 1
#define pb push_back
#define pii pair<int,int>
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

#define int long long

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
int tt;
inline int rd(){
  int x = 0, f = 1; char ch = getchar();
  while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
  while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
  return x * f;
}

void out(int a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) out(a / 10);
  putchar(a % 10 + '0');
}
const int maxn = 2e5+10;
int a[maxn], sum[maxn];
void solve() {
  int n = rd();
  for (int i = 1; i <= n; i++) a[i] = rd();
  for (int i = n; i >= 1; i--) sum[i] = (sum[i+1] + a[i]) % mod;
  int ans = 0;
  for (int i = 1; i < n; i++) ans = (ans + a[i] * sum[i+1] % mod + mod) % mod;
  cout << ans << '\n';
}

signed main(){
//  for (tt = rd(); tt--; )
  solve();
  return 0;
}