#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <const ll M>
class mint {
   private:
    ll x;

   public:
    constexpr mint(ll x = 0) : x((x % M + M) % M) {}
    constexpr ll value() { return x; }
    constexpr mint operator-() const { return mint(-x); }
    constexpr mint &operator+=(const mint &a) {
        if ((x += a.x) >= M) x -= M;
        return *this;
    }
    constexpr mint &operator-=(const mint &a) {
        if ((x += M - a.x) >= M) x -= M;
        return *this;
    }
    constexpr mint &operator*=(const mint &a) {
        (x *= a.x) %= M;
        return *this;
    }
    constexpr mint &operator/=(const mint &a) { return (*this) *= a.inv(); }
    constexpr mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }
    constexpr mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }
    constexpr mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }
    constexpr mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
    constexpr mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    constexpr mint inv() const { return pow(M - 2); }
    constexpr bool operator==(const mint &a) const { return x == a.x; }
    constexpr bool operator!=(const mint &a) const { return x != a.x; }
    friend istream &operator>>(istream &in, mint &a) {
        in >> a.x;
        if (a.x < 0) a.x += M;
        a.x %= M;
        return in;
    }
    friend ostream &operator<<(ostream &out, const mint &a) {
        out << a.x;
        return out;
    }
};

int main() {
    ll N;
    cin >> N;
    vector<mint<1000000007>> A(N);
    vector<mint<1000000007>> S(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    S[0] = A[0];
    for (int i = 1; i < N; i++) S[i] = S[i - 1] + A[i];
    mint<1000000007> ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += A[i] * (S[N - 1] - S[i]);
    }
    cout << ans << endl;
    return 0;
}
