#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair
 
using namespace std;
 
const int N = int(2e3) + 7;
const int mod = int(1e9) + 7;
typedef pair<int, int> pii;
 
int n, a, b, c, d, f[N][N], fac[N], rev[N];
 
void add(int& x, int y) {if((x += y) >= mod) x -= mod;}
int mul(int x, int y) {return 1ll * x * y % mod;}
 
int Pow(int x, int y) {
   int res = 1;
   for(; y > 0; y >>= 1) {
       if(y & 1) res = mul(res, x);
       x = mul(x, x);
   }
   return res;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    cin >> n >> a >> b >> c >> d;
    fac[0] = 1;
    for(int i = 1; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    rev[n] = Pow(fac[n], mod - 2);
    for(int i = n - 1; i >= 0; --i) rev[i] = mul(rev[i + 1], i + 1);
    for(int i = 0; i <= b; ++i) f[0][i] = 1;
    for(int i = 1; i <= n; ++i) {
       for(int j = a; j <= b; ++j) {
          for(int k = c; i - k * j >= 0 && k <= d; ++k)
             add(f[i][j], mul(f[i - k * j][j - 1], mul(Pow(rev[j], k), rev[k])));
          add(f[i][j], f[i][j - 1]);
          //cout << f[i][j] << ' ';
       }
       //cout << '\n';
    }
    cout << mul(f[n][b], fac[n]);
}