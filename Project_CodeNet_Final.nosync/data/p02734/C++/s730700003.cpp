#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) for(int sz=0;sz<int(vec.size());sz++) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 998244353;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

class ModInt {
public:
    long long x;
    constexpr ModInt(const long long x=0) : x((x+MOD)%MOD) {}
    constexpr ModInt& operator+=(const ModInt rhs) {
        x += rhs.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    constexpr ModInt operator+(const ModInt rhs) const {
        return ModInt(*this) += rhs; 
    }
    constexpr ModInt& operator-=(const ModInt& rhs) {
        x -= rhs.x;
        if (x < 0) x += MOD;
        return *this;
    }
    constexpr ModInt operator-(const ModInt rhs) const {
        return ModInt(*this) -= rhs; 
    }
    constexpr ModInt& operator*=(const ModInt& rhs) {
        x = x * rhs.x % MOD;
        return *this;
    }
    constexpr ModInt operator*(const ModInt rhs) const {
        return ModInt(*this) *= rhs; 
    }
    constexpr ModInt& operator/=(const ModInt& rhs) {
        ModInt div = powmod(rhs, MOD - 2);
        (x *= div.x) %= MOD;
        return *this;
    }
    constexpr ModInt operator/(const ModInt rhs) const {
        return ModInt(*this) /= rhs;
    }
    constexpr ModInt powmod(ModInt m, long long p) {
        if (p == 0) return ModInt(1);
        ModInt tmp = powmod(m, p / 2);
        if (p & 1) return tmp * tmp * m;
        else return tmp * tmp;
    }
    constexpr ModInt& operator++() {
        x += 1;
        return *this;
    }
    constexpr ModInt operator++(int) {
        ModInt tmp(*this);
        operator++();
        return tmp;
    }
    constexpr ModInt& operator--() {
        x -= 1;
        return *this;
    }
    constexpr ModInt operator--(int) {
        ModInt tmp(*this);
        operator--();
        return tmp;
    }

    friend ostream& operator<<(ostream& os, const ModInt &rhs) {
        os << rhs.x;
        return os;
    }
    friend istream& operator>>(istream& is, ModInt& rhs) {
        is >> rhs.x;
        return is;
    }
};
bool operator==(const ModInt& lhs, const ModInt& rhs) {
    return lhs.x == rhs.x;
}
bool operator!=(const ModInt& lhs, const ModInt& rhs) {
    return !(lhs == rhs);
}
ModInt powmod(ModInt m, long long p) {
    if (p == 0) return ModInt(1);
    ModInt tmp = powmod(m, p / 2);
    if (p & 1) return tmp * tmp * m;
    else return tmp * tmp;
}

using modi = ModInt;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, s; cin >> n >> s;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    V< V<modi> > dp(n + 1, V<modi>(s + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i + 1][j] += dp[i][j];
            if (j + a[i] > s) continue;
            if (j == 0) {
                if (j + a[i] == s) dp[i + 1][j + a[i]] += modi(i + 1) * modi(n - i);
                else dp[i + 1][j + a[i]] += modi(i + 1);
            } else {
                if (j + a[i] == s) dp[i + 1][j + a[i]] += dp[i][j] * modi(n - i);
                else dp[i + 1][j + a[i]] += dp[i][j];
            }
        }
        // DEBUG_VLL(dp[i + 1]);
    }
    cout << dp[n][s] << '\n';
    return 0;
}
