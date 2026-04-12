// clang-format off
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
#include <cmath>
#include <memory>
using namespace std;

#define DEB(variable) cout << #variable << '=' << variable << endl

#define FOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin); (LoopVariable) < (numberOFend); (LoopVariable)++)
#define DEFOR(LoopVariable,numberOFbegin,numberOFend) for (long long int LoopVariable = (numberOFbegin)-1; (LoopVariable) >= (numberOFend); (LoopVariable)--)
#define REP(LoopVariable,numberOFend) for(long long int LoopVariable = 0;(LoopVariable)<(numberOFend);LoopVariable++)

using llint = long long int;

constexpr long long int linf = numeric_limits<long long int>::max()-5;
constexpr long long int inf= numeric_limits<int>::max()-5;
constexpr long long int mod = 1000000007;
// clang-format on

int main() {
    string s;
    cin >> s;
    llint d;
    cin >> d;
    llint n = s.size();
    vector<vector<vector<llint>>> dp(n + 1, vector<vector<llint>>(2, vector<llint>(d, 0)));
    for(auto x = 0; x <= (int)(s[0] - '0'); x++) {
        dp[0][(x !=(s[0] - '0')? 1 : 0)][x % d] += 1;
    }
    FOR(i, 1, n) {
        REP(smaller, 2) {
            REP(k, d) {
                REP(l, (smaller ?( 9+1) : (1+(int)(s[i] - '0')))) { 
                    dp[i][smaller || l < (int)(s[i] - '0')][(k + l) % d] += dp[i-1][smaller][k];
                    dp[i][smaller || l < (int)(s[i] - '0')][(k + l) % d] %= mod;
                }
            }
        }
    }
    llint result = (mod+dp[n - 1][0][0] + dp[n - 1][1][0] - 1) % mod;
    cout << result << endl;
    return 0;
}
