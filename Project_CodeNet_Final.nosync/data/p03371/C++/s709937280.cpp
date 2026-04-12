#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

template <i64 p>
class fp {
    public:
    i64 x;
    fp() : x(0) {}
    fp(i64 x_) : x((x_ % p + p) % p) {}
    fp operator+() const { return fp(x); }
    fp operator-() const { return fp(-x); }
    fp& operator+=(const fp& y) {
        x += y.x;
        if (x >= p) x -= p;
        return *this;
    }
    fp& operator-=(const fp& y) { return *this += -y; }
    fp& operator*=(const fp& y) {
        x = x * y.x % p;
        return *this;
    }
    fp& operator/=(const fp& y) { return *this *= fp(inverse(y.x)); }
    fp operator+(const fp& y) const { return fp(x) += y; }
    fp operator-(const fp& y) const { return fp(x) -= y; }
    fp operator*(const fp& y) const { return fp(x) *= y; }
    fp operator/(const fp& y) const { return fp(x) /= y; }
    bool operator==(const fp& y) const { return x == y.x; }
    bool operator!=(const fp& y) const { return !(*this == y); }
    i64 extgcd(i64 a, i64 b, i64& x, i64& y) {
        i64 d = a;
        if (b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        } else {
            x = 1;
            y = 0;
        }
        return d;
    }
    i64 inverse(i64 a) {
        i64 x, y;
        extgcd(a, p, x, y);
        return (x % p + p) % p;
    }
};

template <i64 p>
i64 abs(const fp<p>& x) { return x.x; }

template <i64 p>
istream& operator>>(istream& is, fp<p>& x) {
    is >> x.x;
    return is;
}

template <i64 p>
ostream& operator<<(ostream& os, const fp<p>& x) {
    os << x.x;
    return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";
    for (const auto& v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename A, typename T, size_t size>
void fill(A (&ary)[size], const T& val) {
    fill((T*)ary, (T*)(ary + size), val);
}

// x未満の要素の個数を返す
template <typename T>
i64 count_less(const vector<T>& v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

// x以下の要素の個数を返す
template <typename T>
i64 count_less_or_equal(const vector<T>& v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

// xより大きい要素の個数を返す
template <typename T>
i64 count_greater(const vector<T>& v, T x) {
    return end(v) - upper_bound(begin(v), end(v), x);
}

// x以上の要素の個数を返す
template <typename T>
i64 count_greater_or_equal(const vector<T>& v, T x) {
    return end(v) - lower_bound(begin(v), end(v), x);
}

// x未満の要素のうち最大のものを返す
template <typename T>
T max_less(const vector<T>& v, T x) {
    return *(lower_bound(begin(v), end(v), x) - 1);
}

// x以下の要素のうち最大のものを返す
template <typename T>
T max_less_or_equal(const vector<T>& v, T x) {
    return *(upper_bound(begin(v), end(v), x) - 1);
}

// xより大きい要素のうち最小のものを返す
template <typename T>
T min_greater(const vector<T>& v, T x) {
    return *upper_bound(begin(v), end(v), x);
}

// x以上の要素のうち最小のものを返す
template <typename T>
T min_greater_or_equal(const vector<T>& v, T x) {
    return *lower_bound(begin(v), end(v), x);
}

constexpr int inf = 1.01e9;
constexpr i64 inf64 = 4.01e18;
constexpr long double eps = 1e-9;

// 実数値のn分探索のループ回数の上限(2分探索なら50でも十分かもしれない)
constexpr i64 max_loop = 100;

long double tolerance(const long double& a, const long double& b, const long double& epsilon = eps) {
    return epsilon * max({1.l, abs(a), abs(b)});
}

// a<0なら-1, a==0なら0, a>0なら1
int sgn(const long double a, const long double& epsilon = eps) {
    return (a > epsilon) - (a < -epsilon);
}

// a<bなら-1, a==bなら0, a>bなら1
int compare(const long double& a, const long double& b, const long double& epsilon = eps, bool is_relative = true) {
    return sgn(a - b, is_relative ? tolerance(a, b, epsilon) : epsilon);
}

// a==bか?
bool is_equal(const long double& a, const long double& b, const long double& epsilon = eps, bool is_relative = true) {
    return compare(a, b, epsilon, is_relative) == 0;
}

// a<bか?
bool is_less(const long double& a, const long double& b, const long double& epsilon = eps, bool is_relative = true) {
    return compare(a, b, epsilon, is_relative) == -1;
}

// a<=bか?
bool is_less_or_equal(const long double& a, const long double& b, const long double& epsilon = eps, bool is_relative = true) {
    return compare(a, b, epsilon, is_relative) <= 0;
}

// a>bか?
bool is_greater(const long double& a, const long double& b, const long double& epsilon = eps, bool is_relative = true) {
    return compare(a, b, epsilon, is_relative) == 1;
}

// a>=bか?
bool is_greater_or_equal(const long double& a, const long double& b, const long double& epsilon = eps, bool is_relative = true) {
    return compare(a, b, epsilon, is_relative) >= 0;
}

void solve() {
    //constexpr i64 mod = 1'000'000'007;
    i64 A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    i64 ans=inf64;
    rep(i,0,max(X,Y)+1){
        const i64 ab=2*i;
        const i64 a=max<i64>(X-i,0);
        const i64 b=max<i64>(Y-i,0);
        chmin(ans,ab*C+a*A+b*B);
    }

    cout << ans << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
