#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int ans;
string s;
int K;
ll dp[105][4][2];

int main(void) {
    cin >> s;
    scanf("%d", &K);
    int n = (int)s.size();


    ll x = s[0] - '0'; 
    dp[0][1][0] = 1;
    if (x > 1) dp[0][1][1] = x-1;
    dp[0][0][1] =1;
    
    rep(i, 1, n) {
        if (s[i] == '0') rep(j, 1, 4) dp[i][j][0] = dp[i-1][j][0];
        else {
            rep(j, 2, 4) {
                dp[i][j][0] = dp[i-1][j-1][0];
            }
        }
    }

    rep(i, 1, n) {
        ll d = s[i] - '0';
        dp[i][0][1] = 1;
        rep(j, 1, 4) {
            dp[i][j][1] += dp[i-1][j-1][1]*9 + dp[i-1][j][1];
            if (d > 0) dp[i][j][1] += dp[i-1][j-1][0] * (d-1) + dp[i-1][j][0];
        }
    }

    printf("%lld\n", dp[n-1][K][0]+dp[n-1][K][1]);

    return 0;
}

