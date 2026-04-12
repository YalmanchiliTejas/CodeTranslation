#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, s, N) for(ll i{s}; i < (N); i++)
#define rem(i, N, s) for(ll i{N}; i > (s); i--)
using namespace std;using ll = long long;using ld = long double;using P = pair<ll,ll>;const int MOD = (int)1e9+7;const string rt = "\n", sp = " ";
/* 最大公約数 */template<typename T> T gcd(T a, T b){return b != 0 ? gcd(b, a % b) : a;}/* 最小公倍数 */template<typename T> T lcm(T a, T b){return a*b/gcd(a,b);}/* UnionFind */template<typename T> struct UnionFind{vector<T> par;UnionFind(T n) : par(n, -1){}void init(T n){par.assign(n, -1);}T root(T x){if (par[x] < 0) return x;else return par[x] = root(par[x]);}bool issame(T x, T y){return root(x) == root(y);}bool merge(T x, T y){x = root(x); y = root(y);if(x == y) return false;if(par[x] > par[y]) swap(x, y);par[x] += par[y];par[y] = x;return true;}int size(int x) {return -par[root(x)];}};/* コンビネーション */ll comb(ll n, ll r) {if(n < r) return 0;if ( r * 2 > n ) r = n - r;ll dividend = 1;ll divisor  = 1;for (ll i = 1; i <= r; ++i ) {dividend *= (n-i+1);divisor  *= i;}return dividend / divisor;}/* MODコンビネーション */template<typename T> ll combpm(T N_, T C_) {const int NUM_=400001;static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];if (fact[0]==0) {inv[1]=fact[0]=factr[0]=1;for (int i=2;i<=NUM_;++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%MOD, factr[i]=factr[i-1]*inv[i]%MOD;}if(C_<0 || C_>N_) return 0;return factr[C_]*fact[N_]%MOD*factr[N_-C_]%MOD;}/* 多次元ベクター */template<class T>vector<T> mvec(size_t a){return vector<T>(a);}template<class T, class... Ts>auto mvec(size_t a, Ts... ts){return vector<decltype(mvec<T>(ts...))>(a, mvec<T>(ts...));}/* 多次元デック */template<class T>deque<T> mdeq(size_t a){return deque<T>(a);}template<class T, class... Ts>auto mdeq(size_t a, Ts... ts){return deque<decltype(mdeq<T>(ts...))>(a, mdeq<T>(ts...));}/* テスト関数 */void test(ll n){cout << "test" << n << endl;}/* 小数点以下 */void fixsp(ll n){cout << fixed << setprecision(n);}void defsp(ll n){cout << defaultfloat << setprecision(n);}/* 重み付きUnionFind */struct WUnionFind {vector<int> par;vector<int> rank;WUnionFind(int n = 1) {init(n);}void init(int n = 1) {par.resize(n); rank.resize(n);for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;}int root(int x) {if (par[x] == x) {return x;}else {int r = root(par[x]);return par[x] = r;}}bool issame(int x, int y) {return root(x) == root(y);}bool merge(int x, int y) {x = root(x); y = root(y);if (x == y) return false;if (rank[x] < rank[y]) swap(x, y);if (rank[x] == rank[y]) ++rank[x];par[y] = x;return true;}};/* 約数列挙 */deque<ll> divisor(ll n) {deque<ll> ret;for(ll i = 1; i * i <= n; i++) {if(n % i == 0) {ret.push_back(i);if(i * i != n) ret.push_back(n / i);}}sort(begin(ret), end(ret));return (ret);}/* 最頻値 */template<typename T> auto mode(T data){if(data.size() == 1) return *begin(data);sort(begin(data), end(data));typename decltype(data)::value_type mode{};size_t n{},count{1};for(auto iter = adjacent_find(begin(data), end(data)),last = end(data), next = end(data); iter != last;){next = upper_bound(iter, last, *iter);count = distance(iter,next);if(n < count) n = count, mode = *iter;iter = adjacent_find(next, last);}return mode;}/* 中央値 */template<typename T> auto median(T data){sort(begin(data), end(data));size_t median_index = data.size() / 2;return (data.size() % 2 == 0? static_cast<double>(data[median_index] + data[median_index - 1]) / 2: data[median_index]);}/* 整数のpow */template<typename T> ll multi(T a, T b){ll ans{1};rep(i, 0, b) ans *= a;return ans;}/* inf */template<typename T> T inf(){return numeric_limits<T>::max();}/* IO高速化 */void fastio(){ios::sync_with_stdio(false);cin.tie(NULL);}

/* ここからコード開始 */

int main(){
  fastio();
  ll N, M, K;
  cin >> N >> M >> K;
  ll L{},R{};
  rep(i,1,N){
    L+=i*(N-i);
    L%MOD;
  }
  rep(i,1,M){
    R+=i*(M-i);
    R%=MOD;
  }
  cout << (L*M*M + R*N*N)%MOD * combpm(N*M-2,K-2) % MOD << rt;
}