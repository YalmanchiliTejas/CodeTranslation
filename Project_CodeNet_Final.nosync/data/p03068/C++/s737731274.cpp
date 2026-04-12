// インクルード(GCC only)
#include <bits/stdc++.h>

// 長い型名
using namespace std;
typedef long long LL;

// 省略記法
#define INF 1e9
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rrep(i,n) for(int i##_len=(n), i=(i##_len-1); i>=0; ++i)
#define FOR(i,m,n) for(int i=(m), i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define sizei(x) ((int)(x).size())
#define fill(x,y) memset(x,y,sizeof(x))
#define printvector(x) rep(i,sizei(x)){cout << x[i] << endl;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// mod付き四則演算(mod関数のオーバーヘッドが重いかも)
// TODO: 二項係数、離散対数、平方剰余の実装
#define MOD 1000000007
inline LL mod(LL const &a) { return (a % MOD + MOD) % MOD; }
inline LL madd(LL const &a, LL const &b) { return mod(mod(a) + mod(b)); }
inline LL msub(LL const &a, LL const &b) { return mod(mod(a) - mod(b)); }
inline LL mmul(LL const &a, LL const &b) { return mod(mod(a) * mod(b)); }
inline LL mpow(LL a, LL b) {
  LL r = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) (r *= a) %= MOD;
    (a *= a) %= MOD;
  }
  return r;
}
inline LL minv(LL const &a) { return mpow(a, MOD-2); }
inline LL mdiv(LL const &a, LL const &b) { return mod(mod(a) * minv(b)); }


// デバッグ用
#ifdef LOCAL
    #define eprint(...) fprintf(stderr, __VA_ARGS__)
    #define eprintvector(x) printvector(x)
#else
    #define eprint(...) 42
    #define eprintvector(x) 42
#endif

/**************** 便利な関数 ****************/
// 文字列の分割
vector<string> split_impl(string &&s, regex &&r) { return { sregex_token_iterator{s.begin(), s.end(), r, -1}, sregex_token_iterator{} }; }
auto split(string s, string pattern) { return split_impl(move(s), regex{pattern}); }


int main(void)
{
    int N, K;
    string S;

    cin >> N >> S >> K;

    rep(i, N) {
        if (S[i] != S[K-1]) {
            S[i] = '*';
        }
    }

    cout << S << endl;

    return 0;
}
