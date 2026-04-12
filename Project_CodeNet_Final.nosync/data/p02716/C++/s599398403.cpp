#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;

#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)

int main() {
    int N;
    cin >> N;
    vector<ll> A(N+1);
    A[0] = 0;
    repi(i,1, N+1) cin >> A[i];
    vector<ll> dp[2][2];
    rep(i, 2){
        rep(j, 2) {
            dp[i][j].resize(N + 1);
            rep(k, N + 1) dp[i][j][k] = -1e18;
        }
    }
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    dp[0][1][1] = A[1];
    dp[1][1][0] = 0;
    repi(i, 2, N + 1) {
        int j = (i - 1) / 2;
        if (j > 0) {
            dp[0][i % 2][j] = dp[1][(i - 1) % 2][j - 1] + A[i];
            dp[1][i % 2][j] = max(dp[0][(i - 1) % 2][j], dp[1][(i - 1) % 2][j]);
        }
        ++j;
        dp[0][i % 2][j] = dp[1][(i - 1) % 2][j - 1] + A[i];
        dp[1][i % 2][j] = max(dp[0][(i - 1) % 2][j], dp[1][(i - 1) % 2][j]);
    }
    cout << max(dp[0][N%2][N / 2], dp[1][N%2][N / 2]) << endl;
    return 0;
}

