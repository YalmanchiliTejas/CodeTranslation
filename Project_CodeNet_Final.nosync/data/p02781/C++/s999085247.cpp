#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

string N;
int K;
ll dp[101][2][5];

ll solve(){
    dp[0][0][0] = 1;
    REP(i, N.length()){
        REP(k, 4){
            if(N[i] - '0' == 0){
                dp[i + 1][0][k] += dp[i][0][k];
            }
            else{
                dp[i + 1][0][k + 1] += dp[i][0][k];
                dp[i + 1][1][k] += dp[i][0][k];
                dp[i + 1][1][k + 1] += dp[i][0][k] * (N[i] - '1');
            }
            dp[i + 1][1][k] += dp[i][1][k];
            dp[i + 1][1][k + 1] += dp[i][1][k] * 9;
        }
    }
    return dp[N.length()][0][K] + dp[N.length()][1][K];
}

signed main(){
    cin >> N >> K;
    PRINT(solve());
    return 0;
}