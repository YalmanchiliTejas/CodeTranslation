#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define f first
#define s second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ll long long
#define ld double
#define ull unsigned long long
#define PI pair < int, int > 

const int N = 1e6 + 123;
const int M = 123;
const ld Pi = acos(-1);
const ll Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int Sz = 501;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mult(int a, int b) {
  return 1ll * a * b % mod;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}

int n, a[N], l, r, ans[N];

void solve() {
  cin >> n;
  for (int i = 1;i <= n;i++) {
    cin >> a[i];
  }
  l = 1, r = n;
  reverse(a + 1, a + n + 1);
  for (int i = 1;i <= n;i++) {
    if (i & 1) ans[l++] = a[i];
    else ans[r--] = a[i];
  }
  for (int i = 1;i <= n;i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main() {
  #ifdef wws
   freopen("in", "r", stdin);
  // freopen("out", "w", stdout);
  #endif 
  ios_base::sync_with_stdio(0);
  int tt = 1; 
  while(tt--) solve();
  return 0;
}