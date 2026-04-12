#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cinttypes>
#include <cstdint>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <chrono>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

using Field = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
using VI = vector<int>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VC = vector<char>;
using PI = pair<int, int>;

#define FOR(i, s, n) for (int i = s; i < (n); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define ALL(x) x.begin(), x.end()

const long long INF = 1LL<<60;
const int mod = 1000000007;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }

string K;
int D;
vector<vector<vector<ll>>> dp;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> K >> D;

    int N = K.length();

    dp.assign(N + 1, vector<vector<ll>>(2, vector<ll>(D + 1)));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int smaller = 0; smaller < 2; smaller++) {
            for (int d = 0; d < D; d++) {
                int c = K[i] - '0';
                for (int next = 0; next < 10; next++) {

                    if (smaller) {
                        dp[i + 1][smaller][(d + next) % D] += dp[i][smaller][d];
                        dp[i + 1][smaller][(d + next) % D] %= mod;
                    }

                    if (!smaller) {
                        if (next == c) {
                            dp[i + 1][0][(d + next) % D] += dp[i][smaller][d];
                            dp[i + 1][0][(d + next) % D] %= mod;
                        } else if (next < c) {
                            dp[i + 1][1][(d + next) % D] += dp[i][smaller][d];
                            dp[i + 1][1][(d + next) % D] %= mod;
                        }

                    }

                }
            }
        }
    }

    cout << (dp[N][0][0] + dp[N][1][0] - 1 + mod) % mod << endl;

    
    return 0;
}