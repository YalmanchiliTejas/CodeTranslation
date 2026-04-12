#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef pair<int, pi> pii;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

#define fax(i, a) for (int i = 0; i < (a); i++)
#define f0x(i, a, b) for (int i = (a); i < (b); i++)
#define faxd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define f0xd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define memeset memset

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rsz resize

const int mod = 1000000007; // 998244353
const ll INF = 1e18;
const int MX = 200005;
const ld PI = 4*atan((ld)1);

template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }

ll comp(int n, int m) {
  long long num = m - 1;
  long long res_x = 0, res_y = 0;
  res_x = (long long)((num + 1) * (2 * num + 4) * num / 12) % mod;
  res_x = res_x * n * n % mod;
 
  num = n - 1;
  res_y = (long long)((num + 1) * (2 * num + 4) * num / 12) % mod;
  res_y = res_y * m * m % mod;
  return (res_x + res_y) % mod;
}
ll C(int a, int b) {
  long long top = 1, bot = 1;
  for (int i = 0; i < b; ++i) {
    top = top * (a - i) % mod;
    bot = bot * (b - i) % mod;
  }
 
  long long binpow = mod - 2, botinv = 1;
  while (binpow) {
    if (binpow & 1)
      botinv = botinv * bot % mod;
    bot = bot * bot % mod;
    binpow >>= 1;
    binpow %= mod;
  }
  return (top * botinv) % mod;
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int N,M,K; cin >> N >> M >> K;
   ll res = comp(N,M);
   cout << (res * C(N*M-2, K-2))%mod << "\n";
}
