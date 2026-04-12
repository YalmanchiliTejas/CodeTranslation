#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define rep(i, s, N) for(ll i{s}; i < N; i++)
#define rem(i, N, s) for(ll i{N}; i > s; i--)
using namespace std;using ll = long long int;using ld = long double;using P = pair<ll,ll>;const int MOD = (int)1e9+7;const string rt = "\n";const string sp = " ";/* 最大公約数 */template<typename T> T gcd(T a, T b){return b != 0 ? gcd(b, a % b) : a;}/* UnionFind */template<typename T> struct UnionFind{vector<T> par;UnionFind(T n) : par(n, -1){}void init(T n){par.assign(n, -1);}T root(T x){if (par[x] < 0) return x;else return par[x] = root(par[x]);}bool issame(T x, T y){return root(x) == root(y);}bool merge(T x, T y){x = root(x); y = root(y);if(x == y) return false;if(par[x] > par[y]) swap(x, y);par[x] += par[y];par[y] = x;return true;}int size(int x) {return -par[root(x)];}};/* コンビネーション */template<typename T> ll combpm(T N_, T C_) {const int NUM_=400001;static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];if (fact[0]==0) {inv[1]=fact[0]=factr[0]=1;for (int i=2;i<=NUM_;++i) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%MOD, factr[i]=factr[i-1]*inv[i]%MOD;}if(C_<0 || C_>N_) return 0;return factr[C_]*fact[N_]%MOD*factr[N_-C_]%MOD;}/* 多次元ベクター */template<class T>vector<T> multi_vector(size_t a){return vector<T>(a);}template<class T, class... Ts>auto multi_vector(size_t a, Ts... ts){return vector<decltype(multi_vector<T>(ts...))>(a, multi_vector<T>(ts...));}/* テスト関数 */void test(ll n){cout << "test" << n << endl;}/* 小数点以下 */void fixsp(ll n){cout << fixed << setprecision(n);}void defsp(ll n){cout << defaultfloat << setprecision(n);}/* 重み付きUnionFind */struct WUnionFind {vector<int> par;vector<int> rank;WUnionFind(int n = 1) {init(n);}void init(int n = 1) {par.resize(n); rank.resize(n);for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;}int root(int x) {if (par[x] == x) {return x;}else {int r = root(par[x]);return par[x] = r;}}bool issame(int x, int y) {return root(x) == root(y);}bool merge(int x, int y) {x = root(x); y = root(y);if (x == y) return false;if (rank[x] < rank[y]) swap(x, y);if (rank[x] == rank[y]) ++rank[x];par[y] = x;return true;}};/* IO高速化 */void fastio(){ios::sync_with_stdio(false);cin.tie(NULL);}
/* ここからコード開始 */

int main(){
  fastio;
  ll X;
  cin >> X;
  cout << ((X == 7 || X == 5 || X == 3) ? "YES" : "NO") << rt;
}