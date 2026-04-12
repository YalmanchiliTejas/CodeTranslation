#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <numeric>
using namespace std;
typedef long long int ll;

#define EPS (1e-7)
#define INF 1e18
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define PI (acos(-1))

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define rep(i, init, n) for(int i = init; i <(int)(n); i++)

int main() {
    string s;
    ll K;
    cin >> s;
    cin >> K;
    ll leng = s.size();
    ll ans = 0;
    /*
    ll dp[leng][K+1][2];

    REP(i, leng)REP(j, K+1)REP(k, 2) dp[i][j][k] = 0;
*/
    vector<vector<vector<ll>>> dp(leng, vector<vector<ll>> (K+1, vector<ll>(2, 0)));
    if(leng != K) dp[0][K][0] = 1;
    dp[0][K-1][0] = s[0] - '1';
    dp[0][K-1][1] = 1;
    rep(i, 1, leng)REP(j, K+1){
        dp[i][j][0] = dp[i-1][j][0];
        if (j < K) dp[i][j][0] += 9 * dp[i-1][j+1][0];
        if (j < K && s[i] != '0') dp[i][j][0] += dp[i-1][j+1][1] * (s[i] - '1') + dp[i-1][j][1];
        if (s[i] == '0') dp[i][j][1] = dp[i-1][j][1];
        else  if(j < K) dp[i][j][1] = dp[i-1][j+1][1];

    }

    cout << (dp[leng-1][0][0] + dp[leng-1][0][1]) << endl;
    return 0;
}