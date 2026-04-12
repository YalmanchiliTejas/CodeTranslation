#include<algorithm>
#include<bitset>
#include<cassert>
#include<cfloat>
#include<climits>
#include<cmath>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

using lint = long long;
using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define reps(i, n) for(int i = 1, i##_len = (int)(n) ; i <= i##_len ; ++i)
#define rrep(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define rreps(i, n) for(int i = (int)(n) ; i > 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())
#define REVERSE(x) reverse((x).begin(), (x).end())
#define TWINS(x) cout << ((x) ? "Yay!" : ":(") << '\n'

constexpr int IINF = (1 << 30) - 1;
constexpr long long LLINF = 1LL << 61;
constexpr double EPS = 1e-10;

constexpr int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
constexpr int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

template<long long modulus>
class ModInt{
    long long num;

    long long mod(long long n){
        if(n < 0LL){
            n = (n % modulus) + modulus;
        }
        return n % modulus;
    }

    long long ext_gcd(long long a, long long b, long long &x, long long &y){
        if(b == 0LL){
            x = 1;
            y = 0;
            return a;
        }

        long long d = ext_gcd(b, a % b, y, x);
        y -= a / b * x;

        return d;
    }

    long long get_inv(long long n){
        long long x, y;
        ext_gcd(n, modulus, x, y);
        return mod(x);
    }

public:
    constexpr ModInt(const long long n = 0LL) noexcept : num(mod(n)) {}

    long long get(void){
        return num;
    }

    ModInt &operator+=(const ModInt &rhs){
        num += rhs.num;
        if(num >= modulus){
            num -= modulus;
        }
        return *this;
    }

    ModInt &operator-=(const ModInt &rhs){
        if(num < rhs.num){
            num += modulus;
        }
        num -= rhs.num;
        return *this;
    }

    ModInt &operator*=(const ModInt &rhs){
        num = num * rhs.num % modulus;
        return *this;
    }

    ModInt &operator/=(const ModInt &rhs){
        long long inv = get_inv(rhs.num);
        num = num * inv % modulus;
        return *this;
    }

    template<typename T>
    ModInt &operator+=(const T &rhs){
        return *this += ModInt(rhs);
    }

    template<typename T>
    ModInt &operator-=(const T &rhs){
        return *this -= ModInt(rhs);
    }

    template<typename T>
    ModInt &operator*=(const T &rhs){
        return *this *= ModInt(rhs);
    }

    template<typename T>
    ModInt &operator/=(const T &rhs){
        return *this /= ModInt(rhs);
    }

    template<typename T>
    ModInt operator+(const T &rhs) const {
        return ModInt(*this) += ModInt(rhs);
    }

    template<typename T>
    ModInt operator-(const T &rhs) const {
        return ModInt(*this) -= ModInt(rhs);
    }

    template<typename T>
    ModInt operator*(const T &rhs) const {
        return ModInt(*this) *= ModInt(rhs);
    }

    template<typename T>
    ModInt operator/(const T &rhs) const {
        return ModInt(*this) /= ModInt(rhs);
    }

    ModInt &operator=(const ModInt &rhs){
        num = rhs.num;
        return *this;
    }

    template<typename T>
    ModInt &operator=(const T &rhs){
        num = mod(rhs);
        return *this;
    }

    bool operator<(const ModInt &rhs) const {
        return num < rhs.num;
    }
};

template<long long modulus>
std::istream &operator>>(std::istream &lhs, ModInt<modulus> &rhs){
    long long val;
    lhs >> val;
    rhs = val;
    return lhs;
}

template<long long modulus>
std::ostream &operator<<(std::ostream &lhs, ModInt<modulus> rhs){
    lhs << rhs.get();
    return lhs;
}

using mint = ModInt<998244353LL>;

template<typename T>
bool chmax(T& a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool chmin(T& a, T b){
    if(b < a){
        a = b;
        return true;
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }

    vector< vector< vector<mint> > > dp(3, vector< vector<mint> >(n + 1, vector<mint>(s + 1, 0)));
    dp[0][0][0] = 1;

    rep(i, n){
        rep(j, s + 1){
            dp[0][i + 1][j] += dp[0][i][j];
            dp[1][i + 1][j] += dp[0][i][j] + dp[1][i][j];
            dp[2][i + 1][j] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j];
            if(j + a[i] <= s){
                dp[1][i + 1][j + a[i]] += dp[0][i][j] + dp[1][i][j];
                dp[2][i + 1][j + a[i]] += dp[0][i][j] + dp[1][i][j];
            }
        }
    }

    cout << dp[2][n][s] << endl;

    cout << flush;

    return 0;
}