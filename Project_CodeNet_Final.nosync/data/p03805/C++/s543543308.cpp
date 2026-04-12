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

struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const
  {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};

//lower_bound: equal or greater than
//upper_bound: greater than
//Remember "upper_bound is greater"

void dfs(vector<vector<int>>& points, unordered_set<int> seen, int cur, int& count) {
  if(seen.size() == points.size() - 1) {
    //全ての頂点を訪れた
    ++count;
    return;
  }
  
  for(int next : points[cur]) {
    if(seen.find(next) == seen.end()) {
      seen.emplace(next);
      dfs(points, seen, next, count);
      seen.erase(next);
    }
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> points(N + 1, vector<int>());
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    points[a].push_back(b);
    points[b].push_back(a);
  }
  
  unordered_set<int> seen;
  int count = 0;
  seen.emplace(1);
  dfs(points, seen, 1, count);
  
  cout << count << endl;
}
