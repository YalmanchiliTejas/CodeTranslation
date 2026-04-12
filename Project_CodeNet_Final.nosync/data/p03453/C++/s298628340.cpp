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

const long long MOD = 1000000007;
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

using PI = P<int, ll>;
using DIST = P<ll, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int s, t; cin >> s >> t; s--, t--;
    V< V<PI> > edges(n);
    for (int i = 0; i < m; i++) {
        int u, v; ll d; cin >> u >> v >> d;
        u--, v--;
        edges[u].emplace_back(v, d), edges[v].emplace_back(u, d);
    }

    vll dist(n, HIGHINF); dist[s] = 0;
    {
        priority_queue<DIST> pq; pq.push(DIST(0, s));
        while (!pq.empty()) {
            DIST q = pq.top(); pq.pop();
            if (dist[q.second] < -q.first) continue;
            for (PI e: edges[q.second]) {
                if (dist[e.first] > -q.first + e.second) {
                    dist[e.first] = -q.first + e.second;
                    pq.push(DIST(-dist[e.first], e.first));
                }
            }
        }
    }

    V<DIST> didx;
    for (int i = 0; i < n; i++) didx.emplace_back(dist[i], i);
    sort(ALL(didx));
    V<modi> s2t(n, 0), t2s(n, 0);
    s2t[s] = 1, t2s[t] = 1;
    for (DIST di: didx) {
        for (PI e: edges[di.second]) {
            if (dist[di.second] + e.second == dist[e.first]) s2t[e.first] += s2t[di.second];
        }
    }
    reverse(ALL(didx));
    for (DIST di: didx) {
        for (PI e: edges[di.second]) {
            if (dist[di.second] == dist[e.first] + e.second) t2s[e.first] += t2s[di.second];
        }
    }
    // DEBUG_VLL(s2t)
    // DEBUG_VLL(t2s)

    ll mind = dist[t];
    modi cross = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] * 2 == mind) cross += s2t[i] * t2s[i] * s2t[i] * t2s[i];
    }
    for (int i = 0; i < n; i++) {
        for (PI e: edges[i]) {
            if (i > e.first) continue;
            if (min(dist[i], dist[e.first]) + e.second != max(dist[i], dist[e.first])) continue;
            if (min(dist[i], dist[e.first]) * 2 < mind && mind < max(dist[i], dist[e.first]) * 2) {
                cross += s2t[(dist[i] < dist[e.first] ? i : e.first)] * s2t[(dist[i] < dist[e.first] ? i : e.first)] * 
                        t2s[(dist[i] > dist[e.first] ? i : e.first)] * t2s[(dist[i] > dist[e.first] ? i : e.first)];
            }
        }
    }
    cout << s2t[t] * t2s[s] - cross << '\n';
    return 0;
}
