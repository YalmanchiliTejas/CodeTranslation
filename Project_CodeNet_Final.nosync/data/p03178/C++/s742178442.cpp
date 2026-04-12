#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define sq(x) ((x) * (x))
#define err(x) cerr << "["#x"]  " << (x) << "\n";
#define errv(x) {cerr << "["#x"]  [";for(const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}
#define errvn(x, n) {cerr << "["#x"]  [";for(auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}
#define errf() cerr << "\n\n";

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getrnd(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

template <typename T1, typename T2>
bool relax(T1& a, const T2& b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

template <typename T1, typename T2>
bool strain(T1& a, const T2& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

// :::::::::::::::::::::::::::::::

const int N = 1e4 + 3, D = 103;
const ll MOD = 1e9 + 7;

ll dp[N][D][2];

void add(ll& a, ll b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}

void solve() {
    int d;
    string s;
    cin >> s >> d;
    
    int n = (int) s.size();
    for (int i = 0; i < n; ++i)
        s[i] -= '0';
    
    // dp[i][sum][sm] -- number of ways
    
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int sm = 0; sm <= 1; ++sm) {
                for (int now = 0; now <= 9; ++now) {
                    if (!sm && now > s[i]) break;
                    
                    add(dp[i + 1][(j + now) % d][sm || now < s[i]], dp[i][j][sm]);
                }
            }
        }
    }
    
    ll ans = 0;
    add(ans, dp[n][0][0]);
    add(ans, dp[n][0][1]);
    
    --ans;
    if (ans < 0)
        ans += MOD;
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    srand(time(0));
    
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
    
    return 0;
}
