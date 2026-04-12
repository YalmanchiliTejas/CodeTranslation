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
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) std::cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const long long MOD = 1000000007;
const long long HIGHINF = (long long)1e18;
const int INF = (int)1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    ll k; cin >> k;
    V<vvll> dp(s.size() + 1, vvll(k + 1, vll(2, 0)));
    dp[0][0][1] = 1;
    for (ll i = 0; i < s.size(); i++) {
        for (ll j = 0; j < 10; j++) {
            if (j < s[i] - '0') {  // less than
                if (j == 0) {
                    for (ll tk = 0; tk < k + 1; tk++) dp[i + 1][tk][0] += dp[i][tk][0] + dp[i][tk][1];
                } else {
                    for (ll tk = 1; tk < k + 1; tk++) dp[i + 1][tk][0] += dp[i][tk - 1][0] + dp[i][tk - 1][1];
                }
            } else if (j == s[i] - '0') {
                if (j == 0) {
                    for (ll tk = 0; tk < k + 1; tk++) {
                        dp[i + 1][tk][1] += dp[i][tk][1];
                        dp[i + 1][tk][0] += dp[i][tk][0];
                    }
                } else {
                    for (ll tk = 1; tk < k + 1; tk++) {
                        dp[i + 1][tk][1] += dp[i][tk - 1][1];
                        dp[i + 1][tk][0] += dp[i][tk - 1][0];
                    }
                }
            } else {
                if (j == 0) {
                    for (ll tk = 0; tk < k + 1; tk++) dp[i + 1][tk][0] += dp[i][tk][0];
                } else {
                    for (ll tk = 1; tk < k + 1; tk++) dp[i + 1][tk][0] += dp[i][tk - 1][0];
                }
            }
        }
    }

    cout << dp[s.size()][k][0] + dp[s.size()][k][1] << '\n';
    return 0;
}
