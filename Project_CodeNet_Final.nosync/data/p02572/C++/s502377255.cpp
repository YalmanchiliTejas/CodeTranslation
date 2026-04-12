#ifdef LOCAL
#include "libs/debug/print_list.hpp"
#define debug(x) (cout << # x ": " << x << endl)
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}
#else
#define debug(x) ;
#define dev(v, m, n) ;
#endif

// :----------------------------------------

#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;
using pi = pair<int, int>;
using vp = vector<pi>;
using Graph = vector<vector<int>>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

template<int MOD=P>
struct Mod {
public:
    long long signed value;

    Mod(long long signed val): value(val % MOD) {
        if (value < 0) value += MOD;
    }

    constexpr Mod& operator+=(const Mod& other) noexcept { 
        value += other.value;
        value %= MOD;
        return *this;
    }
    constexpr Mod& operator-=(const Mod& other) noexcept {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }
    constexpr Mod& operator*=(const Mod& other) noexcept {
        value *= other.value;
        value %= MOD;
        return *this;
    }

    constexpr Mod operator-() noexcept {
         return value == 0 ? 0 : MOD - value;
    }

    constexpr Mod operator+(const Mod& other) const noexcept { return Mod(*this) += other; }
    constexpr Mod operator-(const Mod& other) const noexcept { return Mod(*this) -= other; }
    constexpr Mod operator*(const Mod& other) const noexcept { return Mod(*this) *= other; }
    constexpr bool operator==(const Mod& other) const noexcept { return this->value == other.value; }
    constexpr bool operator!=(const Mod& other) const noexcept { return this->value != other.value; }
};

signed main() {
    int n;
    cin >> n;

    vi va;
    int sum = 0;

    rep(i, n) {
        capi(a);
        va.push_back(a);
        sum += a;
    }

    Mod ans(0);

    for (auto a: va) {
        Mod x(sum - a);
        x *= a;
        ans += x;
    }

    if (ans.value % 2 == 0) {
        cout << ans.value / 2;
    } else {
        cout << (ans.value + P) / 2;
    }
    
    return 0;
}
