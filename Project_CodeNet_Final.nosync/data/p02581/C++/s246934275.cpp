#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#pragma comment (linker, "/STACK:526000000") 

#include "bits/stdc++.h"
#define int ll

using namespace std;
typedef string::const_iterator State;
#define eps 1e-8L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()


template <std::uint_fast64_t mod>
class modint {
public:
    using u64 = std::uint_fast64_t;
    u64 value = 0;
    modint() :value(0LL) {

    }
    modint(ll a) : value(a% mod) {

    }

    constexpr modint operator+(const modint rhs) const {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const {
        return modint(*this) /= rhs;
    }
    constexpr modint& operator+=(const modint rhs) {
        value += rhs.value;
        if (value >= mod) {
            value -= mod;
        }
        return *this;
    }
    constexpr modint& operator-=(const modint rhs) {
        if (value < rhs.value) {
            value += mod;
        }
        value -= rhs.value;
        value += mod;
        value %= mod;
        return *this;
    }
    constexpr modint& operator*=(const modint rhs) {
        value = (value * rhs.value) % mod;
        return *this;
    }
    constexpr modint& operator/=(modint rhs) {
        ll rem = mod - 2;
        while (rem) {
            if (rem % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            rem /= 2LL;
        }
        return *this;
    }
    bool operator <(modint rhs) const {
        return value < rhs.value;
    }
    friend ostream& operator<<(ostream& os, modint& p) {
        os << p.value;
        return (os);
    }
};
template<typename A>
A pows(A val, ll b) {
    assert(b >= 1);
    A ans = val;
    b--;
    while (b) {
        if (b % 2) {
            ans *= val;
        }
        val *= val;
        b /= 2LL;
    }
    return ans;
}
int dp[2001][2001];
void solve() {	
    int n;
    cin >> n;
    int Maxs[2][3000] = {};
    REP(i, n) {
        Maxs[0][i] = -1e18;
        Maxs[1][i] = -1e18;
        REP(q, n) {
            dp[i][q] = -1e18;
        }
    }
    vector<int> inputs;
    REP(i, 3*n) {
        int a;
        cin >> a;
        inputs.push_back(a - 1);
    }
    dp[inputs[0]][inputs[1]] = 0;
    Maxs[0][inputs[1]] = 0;
    Maxs[1][inputs[0]] = 0;
    int basic = 0;
    int ans = 0;
    int now_maxs = 0;
    for (int i = 2; i < 3 * n - 1; i += 3) {
        vector<int> hoge;
        hoge.push_back(inputs[i]);
        hoge.push_back(inputs[i + 1]);
        hoge.push_back(inputs[i + 2]);
        sort(ALL(hoge));
        if (hoge[0] == hoge[1] and hoge[1] == hoge[2]) {
            basic++;
            continue;
        }
        vector<tuple<int, int, int>> nexts;
        if (hoge[0] == hoge[1]) {
            REP(q, n) {
                nexts.push_back(make_tuple(max({ dp[hoge[2]][q], dp[hoge[0]][q] + 1 ,dp[q][hoge[0]] + 1 }), hoge[2], q));
            }
        }
        if (hoge[1] == hoge[2]) {
            REP(q, n) {
                nexts.push_back(make_tuple(max({ dp[hoge[0]][q], dp[hoge[1]][q] + 1 ,dp[q][hoge[1]] + 1 }), hoge[0], q));
            }
        }
        REP(q, 3) {
            nexts.push_back(make_tuple(dp[hoge[q]][hoge[q]] + 1, hoge[(q + 1) % 3], hoge[(q + 2) % 3]));
        }
        REP(q, 3) {
            nexts.push_back(make_tuple(now_maxs, hoge[q], hoge[(q + 1) % 3]));
        }
        REP(q, 3) {
            REP(i, n) {
                nexts.push_back(make_tuple(Maxs[0][i], i, hoge[q]));
            }
            REP(i, n) {
                nexts.push_back(make_tuple(Maxs[1][i], hoge[q], i));
            }
        }
        REP(i, nexts.size()) {
            dp[get<1>(nexts[i])][get<2>(nexts[i])] = max(dp[get<1>(nexts[i])][get<2>(nexts[i])], get<0>(nexts[i]));
            dp[get<2>(nexts[i])][get<1>(nexts[i])] = dp[get<1>(nexts[i])][get<2>(nexts[i])];
            now_maxs = max(now_maxs, get<0>(nexts[i]));
            Maxs[0][get<2>(nexts[i])] = max(Maxs[0][get<2>(nexts[i])], get<0>(nexts[i]));
            Maxs[1][get<1>(nexts[i])] = max(Maxs[1][get<1>(nexts[i])], get<0>(nexts[i]));
        }
    }
    REP(i, n) {
        REP(q, n) {
            if (i == q and i == inputs.back()) {
                dp[i][q]++;
            }
            ans = max(ans, dp[i][q]);
        }
    }
    cout << ans + basic << endl;
}
#undef int
int main() {
	solve();
}