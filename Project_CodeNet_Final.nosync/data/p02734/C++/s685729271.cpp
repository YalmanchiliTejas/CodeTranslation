#include <bits/stdc++.h>
using namespace std;
constexpr int64_t mod = 998244353;

template <uint32_t mod>
class modint{
    uint64_t value;
public:
    constexpr modint(const int64_t x=0) noexcept: value(x % mod + (x < 0 ? mod : 0)){ }
    constexpr explicit operator uint64_t() const noexcept{ return value; }
    constexpr modint inverse() const noexcept{ return pow(*this, mod-2); }
    constexpr bool operator==(const modint &rhs) const noexcept{ return value == rhs.value; }
    constexpr bool operator!=(const modint &rhs) const noexcept{ return value != rhs.value; }
    constexpr modint operator+() const noexcept{ return modint(*this); }
    constexpr modint operator-() const noexcept{ return modint(mod - value); }
    constexpr modint operator+(const modint &rhs) const noexcept{ return modint(*this) += rhs; }
    constexpr modint operator-(const modint &rhs) const noexcept{ return modint(*this) -= rhs; }
    constexpr modint operator*(const modint &rhs) const noexcept{ return modint(*this) *= rhs; }
    constexpr modint operator/(const modint &rhs) const noexcept{ return modint(*this) /= rhs; }
    constexpr modint &operator+=(const modint &rhs) noexcept{
        if((value += rhs.value) >= mod) value -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{ return *this += mod - rhs.value; }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        if((value *= rhs.value) >= mod) value %= mod;
        return *this;
    }
    constexpr modint &operator/=(const modint &rhs) noexcept{ return *this *= rhs.inverse(); }
    constexpr modint operator++(int) noexcept{
        modint ret(*this);
        if((++value) >= mod) value -= mod;
        return ret;
    }
    constexpr modint operator--(int) noexcept{
        modint ret(*this);
        if((value += mod - 1) >= mod) value -= mod;
        return ret;
    }
    constexpr modint &operator++() noexcept{ return *this += 1; }
    constexpr modint &operator--() noexcept{ return *this -= 1; }
    friend std::ostream &operator<<(std::ostream &os, const modint<mod> &x){ return os << x.value; }
    friend std::istream &operator>>(std::istream &is, modint<mod> &x){
        int64_t i;
        is >> i;
        x = modint<mod>(i);
        return is;
    }
    friend constexpr modint<mod> pow(const modint<mod> &x, uint64_t y){
        modint<mod> ret{1}, m{x};
        while(y > 0){
            if(y & 1) ret *= m;
            m *= m;
            y >>= 1;
        }
        return ret;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, s, a[3000];
    cin >> n >> s;
    for(int i=0;i<n;++i) cin >> a[i];

    static modint<mod> dp[3000], ans = 0;
    for(int i=0;i<n;++i){
        dp[0] = i + 1;
        if(a[i] > s) continue;
        ans += dp[s - a[i]] * (n - i);
        for(int j=s-1;j-a[i]>=0;--j){
            dp[j] += dp[j-a[i]];
        }
    }
    cout << ans << endl;

    
    return 0;
}