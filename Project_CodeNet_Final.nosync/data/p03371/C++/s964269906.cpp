#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;  
using namespace std;

typedef long long ll;

typedef tree<
pair <int, int>,
null_type,
less<pair <int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
os;

double getTime() {
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void print() {};

template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}

const int N = 55;

int g[N][N];
int dp[N][N][2];
int n, m;

int get(int x, int y) {
  return x == 0 and y == 1;
}

int go(int x, int y, int last) {
  if(x == n - 1 and y == m - 1) {
    return get(last, g[x][y]);
  }
  if(dp[x][y][last] != -1) return dp[x][y][last];
  int gettis = get(last, g[x][y]);
  int cur = 1e9;
  if(x + 1 < n) cur = min(cur, gettis + go(x + 1, y, g[x][y]));
  if(y + 1 < m) cur = min(cur, gettis + go(x, y + 1, g[x][y]));
  return dp[x][y][last] = cur;
}

int main() {
  ll a, b, c; read(a, b, c);
  ll x, y; read(x, y);
  ll p = min(a + b, c + c);
  ll q = min(a, 2 * c);
  ll r = min(b, 2 * c);
  ll D = min(x, y);
  ll total = D * p;
  x -= D, y -= D;
  if(x) {
    total += q * x;
  }
  if(y) {
    total += r * y;
  }
  print(total);
}