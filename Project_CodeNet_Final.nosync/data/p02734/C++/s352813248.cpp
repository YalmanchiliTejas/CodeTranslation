#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i = a;i<=n;++i)
#define per(i,a,n) for (int i = n;i>=a;--i)
#define all(x) (x).begin(), (x).end()     
#define SZ(x) ((int)x.size())

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

mt19937 mrand(random_device{}());
ll rnd(ll a, ll b) { return a + mrand() % (b - a + 1); }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int mod = 998244353;
const int N = 3010;
int dp[N][N];
int n, s;

int mul(int a, int b) {
      a %= mod;
      b %= mod;
      ll c = 1ll * a * b;
      c %= mod;
      return c;
}

int add(int a, int b) {
      a %= mod;
      b %= mod;
      a += b;
      a %= mod;
      if (a < 0) a += mod;
      return a;
}

int main() {
      ios::sync_with_stdio(false); cin.tie(0);
#ifdef arrias
      freopen("a.txt", "r", stdin);
#endif
      cin >> n >> s;
      int ans = 0;
      rep(i, 1, n) {
            int a;
            cin >> a;
            rep(j, 0, s) {
                  dp[i][j] = add(dp[i][j], dp[i - 1][j]);
                  if (j >= a) {
                        dp[i][j] = add(dp[i][j], dp[i - 1][j - a]);
                        if (j == s) {
                              ans = add(ans, mul(dp[i - 1][s - a], (n - i + 1)));
                        }
                  }     
            }
            dp[i][a] = add(dp[i][a], i);
            if (a == s) {
                  ans = add(ans, mul(n - i + 1, i));
            }
      }
      cout << ans << "\n";
      return 0;
}