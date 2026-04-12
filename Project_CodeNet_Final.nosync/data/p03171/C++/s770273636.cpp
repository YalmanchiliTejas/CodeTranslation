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

int main(){

    llint n;
    cin >> n;
    vector<llint> v(n);
    REP(i,n){
        cin >> v[i];
    }
    vector<vector<llint>> dp(n + 1, vector<llint>(n + 1, 0));
    FOR(length,1,n+1){
        REP(l,n-length+1){
            llint r = l + length;
            dp[l][r] = max(v[l] - dp[l + 1][r], v[r-1] - dp[l][r - 1]);
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}
