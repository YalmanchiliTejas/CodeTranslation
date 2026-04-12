#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }

const int maxn = 3005;
int n, s;
int dp[maxn][maxn], a[maxn];

int f(int i, int k) {
  if(k > s) return 0;
  if(k == s) return n - i + 1;
  if(i == n) return 0;
  if(dp[i][k] != -1) return dp[i][k];
  return dp[i][k] = add(f(i + 1, k), f(i + 1, k + a[i]));
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  cin >> n >> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  f(0, 0);
  int res = 0;
  for(int l = 0; l < n; l++) {
    res = add(res, dp[l][0]);
  }
  cout << res;
}