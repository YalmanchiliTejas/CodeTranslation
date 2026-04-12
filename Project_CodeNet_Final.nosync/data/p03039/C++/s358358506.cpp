#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define FOR(i,a,b) for (ll i = (a) ; i <= (b); ++i)
#define all(x) (x).begin(), (x).end()
//#define repitr(itr, st) for(auto itr = st.begin(); itr != st.end(); ++itr)
#define P_B push_back
#define PO_B pop_back
#define E_B emplace_back
#define M_P make_pair
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl
//#define print(x) printf("%d\n", x)

using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<vector<int> >;
using VVL = vector<vector<ll> >;
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
//const ll LINF = (ll)1e18 - 1;
//const int INF = 1e9 - 1;
//int:±2*10^9くらい　ll:±9*10^18くらい

//https://drken1215.hatenablog.com/entry/2018/06/08/210000
//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
const int MAX = 200005;
const int MOD = 1000000007;

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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007; //998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

using VM = vector<mint>;
using VVM = vector<vector<mint> >;



void Main(){
	int N, M, K, nm;
	cin >> N >> M >> K;
	nm = N * M;

	COMinit();

	ll com1;

	com1 = COM(nm-2, K-2);

	mint alln = 0, allm;
	FOR(i, 1, N-1){
		alln += i * (N-i);
	}
	FOR(i, 1, M-1){
		allm += i * (M-i);
	}

	mint com = com1, ans;
	ans = com * (alln * M * M + allm * N * N);

	cout << ans << endl;



}

int main()
{
	cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();

  return 0;
}
