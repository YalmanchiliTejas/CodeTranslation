#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<int param> class ModInt {
    using Z = int;
    using N = unsigned int;
    using ZZ = long long;
    using NN = unsigned long long;
    struct {} constexpr static exact{};

    // Using Z deliberately to avoid Z -> N promotion.
    template<class Ret = Z&>
    static auto modulo() -> std::enable_if_t<(param<=0), Ret> { static Z mod = 0; return mod; }
    template<class Ret = const Z>
    static auto mod() -> std::enable_if_t<(param<=0), Ret> { return modulo(); }
    template<class Ret = const Z>
    static constexpr auto mod() -> std::enable_if_t<(param>0), Ret> { return param; }
    // std::swap is not a constexpr function in C++14
    static constexpr void swap(Z &a, Z &b){ Z tmp = a; a = b; b = tmp; }

    Z val;
    constexpr ModInt(decltype(exact), const N v) : val(v) {}

public:
    template<class Arg = Z>
    static void set_modulo(const std::enable_if_t<(param<=0), Arg> mod) { modulo() = mod; }

    constexpr ModInt() : val(0) {}
    constexpr ModInt(Z v) : val((v%=mod()) < 0 ? v+mod() : v) {}
    constexpr ModInt(ZZ v) : val((v%=mod()) < 0 ? v+mod() : v) {}

    constexpr int get_val() const { return val; }

    constexpr ModInt inv() const {
        Z a = mod(), b = val;
        Z x = 0, u = 1;
        while (b) {
            const Z t = a / b;
            swap(a -= t * b, b);
            swap(x -= t * u, u);
        }
        return ModInt(exact, x < 0 ? x+mod() : x);
    }

    constexpr explicit operator int() const { return val; }
    constexpr ModInt operator+() const { return *this; }
    constexpr ModInt operator-() const { return ModInt(exact, val ? mod() - val : 0); }

    constexpr ModInt operator++(){ if(++val == mod()) val = 0; return *this; }
    constexpr ModInt operator--(){ val = (val == 0 ? mod()-1 : val-1); return *this; }
    constexpr ModInt operator++(int){ const ModInt res(*this); ++*this; return res; }
    constexpr ModInt operator--(int){ const ModInt res(*this); --*this; return res; }

    constexpr bool operator==(const ModInt &rhs) const { return val == rhs.val; }
    constexpr bool operator!=(const ModInt &rhs) const { return val != rhs.val; }
    constexpr ModInt &operator+=(const ModInt &rhs){
        if((val += rhs.val) >= mod()) val -= mod();
        return *this;
    }
    constexpr ModInt &operator-=(const ModInt &rhs){
        if(rhs.val && (val += mod()-rhs.val) >= mod()) val -= mod();
        return *this;
    }
    constexpr ModInt &operator*=(const ModInt &rhs){ val = (NN)(val) * rhs.val % mod(); return *this; }
    constexpr ModInt &operator/=(const ModInt &rhs){ return *this *= rhs.inv(); }

    constexpr ModInt pow(long long e) const {
        if(e < 0) return pow(-e).inv();
        NN res = 1, b = val;
        for(; e; e >>= 1, (b *= b) %= mod()) if(e&1) (res *= b) %= mod();
        return ModInt(exact, res);
    }
    friend constexpr ModInt operator+(ModInt lhs, const ModInt &rhs){ return lhs += rhs; }
    friend constexpr ModInt operator-(ModInt lhs, const ModInt &rhs){ return lhs -= rhs; }
    friend constexpr ModInt operator*(ModInt lhs, const ModInt &rhs){ return lhs *= rhs; }
    friend constexpr ModInt operator/(ModInt lhs, const ModInt &rhs){ return lhs /= rhs; }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &v) { return os << v.val; }
    friend std::istream &operator>>(std::istream &is, ModInt &v) {
        int val;
        is >> val;
        v = ModInt(val);
        return is;
    }
};

using mint = ModInt<1000000007>;


mint dp[10005][105][2];

int main() {
    string K;
    int D;
    cin >> K >> D;

    ll n = K.size();

    dp[0][0][0] = 1;
    REP(i, n) REP(j, D) {
        // 最上位は非０
        int v = stoi(K.substr(i, 1));

        // ぴったり → ぴったり
        dp[i + 1][(j + v) % D][0] += dp[i][j][0];

        // ぴったり → 未満
        for (int k = 0; k < v; k++)  dp[i + 1][(j + k) % D][1] += dp[i][j][0];

        // 未満 → 未満
        for (int k = 0; k <= 9; k++) dp[i + 1][(j + k) % D][1] += dp[i][j][1];            
    }

    cout << dp[n][0][0] + dp[n][0][1] - 1 << endl;

    return 0;
}