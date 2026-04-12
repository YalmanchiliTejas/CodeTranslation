#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define rea(i, a, b) for (int i = (a); i < (b); i++)
#define reab(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(),(a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
inline ll divceil(ll a, ll b){return (a+b-1) / b;}
const int MOD = 1000000007;
/* END OF TEMPLATE */

// http://drken1215.hatenablog.com/entry/2018/06/08/210000
const int MAX = 200010;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    COMinit();
    ll n, m, k;
    cin >> n >> m >> k;
    ll ansn = 0, ansm = 0, ans;
    ll anstemp = 0;
    ll m2 = m*m % MOD;
    ll n2 = n*n % MOD;
    rea(i, 1, n){
        anstemp = (n-i) * COM(n*m-2, k-2) % MOD;
        anstemp = anstemp * i % MOD;
        ansn = (ansn + anstemp) % MOD;
    }
    ansn = ansn * m2 % MOD;
    rea(i, 1, m){
        anstemp = (m-i) * COM(n*m-2, k-2) % MOD;
        anstemp = anstemp * i % MOD;
        ansm = (ansm + anstemp) % MOD;
    }
    ansm = ansm * n2 % MOD;
    ans = (ansn + ansm) % MOD;
    cout << ans << endl;
}