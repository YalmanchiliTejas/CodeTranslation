#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <utility>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PII;
LL MOD = 1000000007;

int main() {
    string K;
    int D;
    cin >> K >> D;
    int N = K.size();
    vector<vector<LL>> dp(N+1, vector<LL>(D, 0)); 


    dp[0][0] = 1;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<D; j++) {
            for(int k=0; k<10; k++) {
                int to = (j+k) % D;
                dp[i][to] += dp[i-1][j];
                dp[i][to] %= MOD;
            }
        }
    }
    /*
    for(int i=0; i<N; i++, cout << endl)
        for(int j=0; j<D; j++) {
            cout << dp[i][j] << " ";
        }
*/

    int sum = 0;
    LL ans = MOD - 1;
    for(int i=0; i<N; i++) {
        int digit = (K[i] - '0');
        for(int j=0; j<digit; j++) {
            int ind = ((0 - sum - j) + 10 * D ) % D;
            ans += dp[N-i-1][ind];
            ans %= MOD;
        }
        sum += digit;
        sum %= D;

    }
    //cout << sum << endl;
    if(sum % D == 0) ans++;
    cout << ans % MOD << endl;


    return 0;
}