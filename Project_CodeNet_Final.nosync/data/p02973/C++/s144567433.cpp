//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr ll INF = 1e16;
constexpr ll MOD = 1000000007;

// modint: mod 計算を int を扱うように扱える構造体
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) v += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
        return is >> x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};

using mint = Fp<((int)MOD)>;

#define rep(i, N) for(ll i=0; i<(N); ++i)

template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return 1; } else { return 0; }}
template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return 1; } else { return 0; }}


ll max(ll a, ll b) {return a < b ? b : a; }
ll min(ll a, ll b) {return a > b ? b : a; }
double maxf(double a, double b) { return a < b ? b : a; }

template<typename T> inline string toString(const T &a) {
  ostringstream oss; oss << a; return oss.str();
}

ll gcd(ll x, ll y) { return x % y ? gcd(y, x % y) : y; }
ll lcm(ll x, ll y) { return x * y / gcd(x, y); }

//lower_bound: 以上
//upper_bound: より大きい
//upperのほうがより大きいと覚える
int main() {
  //E: sequence decomposing
  //いろんな方法でやってみる．別に最長広義減少列とみなさなくても良い
  
  int N;
  cin >> N;
  vector<ll> A(N); 
  rep(i, N) cin >> A[i];
  
  //まず，multiset
  //各要素は，その色の集合の，最後の要素（最大値）を保持する
  //更新時は，追加する要素より小さい値のうち，できるだけ大きい値を更新する．（そのほうが後の選択肢が広がるので）
  //っていうか
  vector<ll> s;
  //deque内はsortされるらしい => lower_boundが使える（メモリ領域が連続していないのに使えるのか．インデックスアクセスがO(1)でできるからか）．前方イタレータの要件を満たせば良い
  
  for(int i=0; i<N; ++i) {
    auto itr = lower_bound(s.rbegin(), s.rend(), A[i]);
    if(itr == s.rbegin()) {
      s.push_back(A[i]);
    } else {
      itr--;
      *itr = A[i];
    }
  }
  
  cout << s.size() << endl;
}

//index がずれた (1-base)
//余計な変数でRE
//それでも一部WA
