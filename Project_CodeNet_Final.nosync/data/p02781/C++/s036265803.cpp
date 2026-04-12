#include <iostream>
#include <fstream>
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
#define errp(x) cerr << "["#x"]  {" << ((x).first) << ", " << ((x).second) << "}\n";
#define errv(x) {cerr << "["#x"]  [";for(const auto& ___ : (x)) cerr << ___ << ", "; cerr << "]\n";}
#define errvn(x, n) {cerr << "["#x"]  [";for(auto ___ = 0; ___ < (n); ++___) cerr << (x)[___] << ", "; cerr << "]\n";}
#define errf() cerr << "\n\n";

//#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer","inline")
//#pragma GCC option("arch=native","tune=native","no-zero-upper")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")

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

const int N = 103;

ll dp[N][2][N];

void solve() {
    string s;
    int k;
    cin >> s >> k;
    
    int n = s.size();
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int sm = 0; sm <= 1; ++sm) {
            for (int c = 0; c < n; ++c) {
                for (int cur = 0; cur <= 9; ++cur) {
                    int off = cur != 0;
                    if (sm)
                        dp[i + 1][sm][c + off] += dp[i][sm][c];
                    else if (cur <= s[i] - '0')
                        dp[i + 1][(s[i] - '0' != cur)][c + off] += dp[i][sm][c];
                }
            }
        }
    }
    cout << dp[n][0][k] + dp[n][1][k] << '\n';
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
