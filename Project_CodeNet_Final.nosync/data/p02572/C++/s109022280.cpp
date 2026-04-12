#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

const long long MOD = 1000000007;

template<int M, bool IsPrime = false>
class Modulo {
    int n;

    static typename std::enable_if<IsPrime, ll>::type inv(ll a, ll p) {
        return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
    }

public:
    Modulo() : n(0) { ; }

    Modulo(int m) : n(m) {
        if (n >= M)
            n %= M;
        else if (n < 0)
            n = (n % M + M) % M;
    }

    Modulo(ll m) {
        if (m >= M)
            m %= M;
        else if (m < 0)
            m = (m % M + M) % M;
        n = m;
    }

    explicit operator int() const { return n; }

    explicit operator ll() const { return n; }

    bool operator==(const Modulo &a) const { return n == a.n; }

    Modulo &operator+=(const Modulo &a) {
        n += a.n;
        if (n >= M) n -= M;
        return *this;
    }

    Modulo &operator-=(const Modulo &a) {
        n -= a.n;
        if (n < 0) n += M;
        return *this;
    }

    Modulo &operator*=(const Modulo &a) {
        n = (ll(n) * a.n) % M;
        return *this;
    }

    Modulo operator+(const Modulo &a) const {
        Modulo res = *this;
        return res += a;
    }

    Modulo operator-(const Modulo &a) const {
        Modulo res = *this;
        return res -= a;
    }

    Modulo operator-() const { return Modulo(0) - *this; }

    Modulo operator*(const Modulo &a) const {
        Modulo res = *this;
        return res *= a;
    }

    Modulo operator^(ll m) const {
        if (m == 0) return Modulo(1);
        const Modulo a = *this;
        Modulo res = (a * a) ^(m / 2);
        return m % 2 ? res * a : res;
    }

    typename std::enable_if<IsPrime, Modulo>::type
    operator/(const Modulo &a) const {
        return *this * inv(ll(a), M);
    }

    typename std::enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
        return *this *= inv(ll(a), M);
    }

    friend bool is_zero(const Modulo &x) { return int(x) == 0; }

    friend int abs(const Modulo &x) { return int(x); }

    static Modulo fact(int n, bool sw = true) {
        static std::vector<Modulo> v1 = {1}, v2 = {1};
        if (n >= (int) v1.size()) {
            const int from = v1.size(), to = n + 1024;
            v1.reserve(to);
            v2.reserve(to);
            for (int i = from; i < to; ++i) {
                v1.push_back(v1.back() * Modulo<M, true>(i));
                v2.push_back(v2.back() / Modulo<M, true>(i));
            }
        }
        return sw ? v1[n] : v2[n];
    }

    static Modulo comb(int a, int b) {
        if (b < 0 || b > a) return 0;
        return Modulo::fact(a, true) * Modulo::fact(b, false) *
               Modulo::fact(a - b, false);
    }
};

typedef Modulo<1000000007, true> mInt;


void solve(long long N, std::vector<long long> A) {
    mInt ans = 0;
    mInt sum = 0;
    for (int i = 0; i < N; i++)
        sum += A[i];
    for(int i = 0 ; i < N ; i++)
        ans += (sum - A[i]) * A[i];
    cout << int(ans/2) << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
