#include <bits/stdc++.h>

using namespace std;

template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;
    u64 a;

    public:

    template <class INT>
    constexpr modint(const INT x = 0) noexcept : a(x >= 0 ? x % Modulus : x % int_fast64_t(Modulus) + Modulus) {}
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
        rhs *= rhs;
        exp /= 2;
        }
        return *this;
    }

    constexpr bool operator<(const modint& rhs) const noexcept {return this->a < rhs.a;}
    constexpr bool operator>(const modint& rhs) const noexcept {return rhs < *this;}
    constexpr bool operator<=(const modint& rhs) const noexcept {return !(*this > rhs);}
    constexpr bool operator>=(const modint& rhs) const noexcept {return !(*this < rhs);}
    constexpr bool operator==(const modint& rhs) const noexcept {return this->a == rhs.a;}
    constexpr bool operator!=(const modint& rhs) const noexcept {return !(*this == rhs);}

    constexpr modint& operator++() noexcept {
        *this += modint(1);
        return *this;
    }
    constexpr modint operator++(int) noexcept {
        modint tmp(*this);
        ++(*this);
        return tmp;
    }
    constexpr modint& operator--() noexcept {
        *this -= modint(1);
        return *this;
    }
    constexpr modint operator--(int) noexcept {
        modint tmp(*this);
        --(*this);
        return tmp;
    }
    constexpr modint operator-() const noexcept {
        return modint(0) - *this;
    }

    template <std::uint_fast64_t M>
    friend constexpr std::ostream& operator<<(std::ostream& os, const modint<M>& rhs) noexcept {
        os << rhs.a;
        return os;
    }
    template <std::uint_fast64_t M>
    friend constexpr std::istream& operator>>(std::istream& is, modint<M>& rhs) noexcept {
        int64_t tmp;
        is >> tmp;
        rhs = modint(tmp);
        return is;
    }

    constexpr modint pow(const u64 k) const noexcept {
        if (k == 0)
            return 1;
        if (k % 2 == 0){
            modint res = pow(k / 2);
            return res * res;
        }
        return pow(k - 1) * modint(*this);
    }

    template <typename T>
    operator const T (){return a;}
};


int main(){
    const constexpr int64_t p = 1e9 + 7;
    using mint = modint<p>;
    int n;
    cin >> n;
    vector<mint> A(n);
    for (auto &a: A) cin >> a;
    mint S = accumulate(A.begin(), A.end(), mint(0));
    mint ans = 0;
    for (const auto &a: A){
        ans += a * S;
        ans -= a * a;
    }

    cout << ans / 2 << endl;
}