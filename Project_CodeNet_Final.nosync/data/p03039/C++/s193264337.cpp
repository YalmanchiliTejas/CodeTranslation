#include <bits/stdc++.h>

#define debug(x) cout <<"DEBUG"<<" "<< #x << ":" << x << '\n'
#define rep(i,n) for(int_fast32_t i = 0; i < ((int_fast32_t)(n)); i++)   // 0-indexed up
#define rep1(i,n) for(int_fast32_t i = 1; i <= ((int_fast32_t)(n)); i++) // 1-indexed up
#define rrep(i,n) for(int_fast32_t i = ((int_fast32_t)(n)-1); i >= 0; i--)  // 0-indexed down
#define rrep1(i,n) for(int_fast32_t i = ((int_fast32_t)(n)); i >= 1; i--)   // 1-indexed down
#define all(x) (x).begin(),(x).end()

using namespace std;

template<typename T>
using vec = vector<T>;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
using u32 = uint_fast32_t;
using u64 = uint_fast64_t;
using ll = long long;
using ld = long double;
using vi = vec<int_fast32_t>;
using vl = vec<int_fast64_t>;
using vld = vec<ld>;
using vii = vec<vi>;
using PII = pair<int_fast32_t, int_fast32_t>;

template<class T>
using maxheap = std::priority_queue<T>;
template<class T>
using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<class T,class U> inline bool chmax(T &a, const U &b){if(a<b){a=b;return 1;}return 0;}
template<class T,class U> inline bool chmin(T &a, const U &b){if(a>b){a=b;return 1;}return 0;}

const ld Pi = std::acos(-1.0L);
constexpr ll infll = (1LL<<62)-1;
constexpr int inf = (1<<30)-1;
const int mod = 1000000007;
// const int mod = 998244353;

/*MOD int=============================*/
template<std::int_fast64_t Mod>
class modint {
public:
    using i64 = std::int_fast64_t;
    i64 val;
    //constructor
    constexpr modint(const i64 p=0) noexcept : val(p>=0 ? p%Mod : (Mod+(p%Mod))%Mod) {}

    //std::cin, std::cout
    friend std::ostream &operator<<(std::ostream &os, const modint &x) {
        return os << x.val;
    }
    friend std::istream &operator>>(std::istream &is, modint &x) {
        is >> x.val;
        x.val %= Mod;
        if(x.val < 0) x.val += Mod;  // <- 負数対応
        return is;
    }

    //operator
    constexpr modint operator+(const modint b) const noexcept { return modint(*this) += b; }

    constexpr modint operator-(const modint b) const noexcept { return modint(*this) -= b; }

    constexpr modint operator*(const modint b) const noexcept { return modint(*this) *= b; }

    constexpr modint operator/(const modint b) const noexcept { return modint(*this) /= b; }

    constexpr modint operator-() const noexcept { return modint() - *this; }

    constexpr bool operator==(const modint &b) const noexcept { return this->val == b.val; }

    constexpr bool operator!=(const modint &b) const noexcept { return this->val != b.val; }

    constexpr modint &operator=(const modint b) noexcept {
        val = b.val;
        return *this;
    }
    constexpr modint &operator=(const i64 b) noexcept {
        val = modint<Mod>(b).val;
        return *this;
    }
    constexpr modint &operator+=(const modint b) noexcept {
        if((val += b.val) >= Mod) val -= Mod;
        return *this;
    }
    constexpr modint &operator-=(const modint b) noexcept {
        if(val < b.val) val += Mod;
        val -= b.val;
        return *this;
    }
    constexpr modint &operator*=(const modint b) noexcept {
        val = val * b.val % Mod;
        return *this;
    }
    constexpr modint &operator/=(modint b) noexcept {
        val *= b.inverse().val;
        val %= Mod;
        return *this;
    }
    constexpr modint inverse() noexcept {
        i64 m=Mod, u=1, v=0, t=1;
        while(m) {
            t = val/m;
            val -= t*m; std::swap(val,m);
            u -= t*v; std::swap(u,v);
        }
        return modint(u);
    }
    // calc val^n
    constexpr  modint pow(i64 n) noexcept {
        modint res = 1, a = val;
        while(n > 0) {
            if(n & 1) res = res * a;
            a = a * a;
            n >>= 1;
        }
        return res;
    }
};
using mint = modint<mod>;

/*Binomial=============================================*/
class Binomial {
private:
    const int MAX;
    const int MOD;
    std::vector<long long> fac, finv, inv;

public:
    Binomial(int MAX = 510000, int MOD = 1000000007): MAX(MAX), MOD(MOD)
    {
        fac.resize(MAX);
        finv.resize(MAX);
        inv.resize(MAX);
        // Build'Binomial-table'
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    long long calc(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

/*FUNCs=================================================*/


/*MAIN==================================================*/
signed main(){
    double START_TIME = clock();
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
//    cout << fixed << setprecision(15);

    i32 n,m,k; cin >> n >> m >> k;
    mint ans = 1;
    // 数え上げの順番を変える問題
    // for(all placing) for(all pair) {add pair's distance}
    // から
    // for(all pair) for(all placing) if(placing includes pair) {add pair's distance}
    // へ
    // 各pairに対してそれが出てくる配置の数はBinomial(nm-2, k-2)で決まり、
    // それらでpair間の距離は一定なのでfor(all placing) if(placing includes pair)
    // のフェーズが消える
    // 各pairの間で縦の距離と横の距離は独立して数えられるので
    // pair全通りに対する縦の距離の合計は
    // SUM[ d(n-d) * m * m , d = 1, n-1]
    // 横の距離も同様に求める
    // 答えは
    // SUM[ distance_i * Binomial(nm-2, k-2) ]
    // = Binomial(nm-2, k-2) * SUM[ distance_i ]
    // = Binomial(nm-2, k-2)
    //      * { SUM[ d(n-d) * m * m , d = 1, n-1]
    //              + SUM[ d(m-d) * n * n , d = 1, m-1] }
    // である...fin

    Binomial com(510000, mod);
    ans = com.calc(n*m-2, k-2);

    ans *= (m*m*(n-1)*n*(n+1)/6 + n*n*(m-1)*m*(m+1)/6);

    cout << ans << '\n';

//     printf("ElapsedTime: %5.3f ms\n",1000*((clock()-START_TIME)/CLOCKS_PER_SEC));
}
