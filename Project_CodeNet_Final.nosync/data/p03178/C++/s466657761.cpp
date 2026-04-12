#include <bits/stdc++.h>

using namespace std;

template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;
    u64 a;

    public:

    template <class INT>
    constexpr modint(const INT x = 0) noexcept : a(x >= 0 ? x % Modulus : x % Modulus + Modulus) {}
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
    constexpr bool operator>(const modint& rhs) const noexcept {return rhs < this;}
    constexpr bool operator<=(const modint& rhs) const noexcept {return !(this > rhs);}
    constexpr bool operator>=(const modint& rhs) const noexcept {return !(this < rhs);}
    constexpr bool operator==(const modint& rhs) const noexcept {return this->a == rhs.a;}
    constexpr bool operator!=(const modint& rhs) const noexcept {return !(this == rhs);}

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
    string S;
    cin >> S;
    int d;
    cin >> d;
    int n = S.length();
    const int64_t p = 1e9 + 7;
    using mint = modint<p>;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        A[i] = S[i] - '0';
    vector<vector<vector<mint>>> DP(n + 1, vector<vector<mint>>(d, vector<mint>(2)));
    DP[0][0][1] = 1;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < d; j++){
            for (int k = 0; k < 10; k++){
                if (k < A[i])
                    DP[i + 1][(j + k) % d][0] += DP[i][j][1];
                if (k == A[i])
                    DP[i + 1][(j + k) % d][1] += DP[i][j][1];
                DP[i + 1][(j + k) % d][0] += DP[i][j][0];
            }
        }
    }

    cout << DP[n][0][1] + DP[n][0][0] - mint(1) << endl;
}