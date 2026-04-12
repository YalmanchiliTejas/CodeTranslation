

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<ll>> dp(N, vector<ll>(3, -(1LL << 61))); // N/2, N/2+1
    dp[0][2] = 0;
    if(N % 2 == 1) {
        dp[0][0] = A[0];
        dp[1][1] = A[1];
    }
    else {
        dp[0][1] = A[0];
        dp[1][2] = A[1];
    }
    rep(i, 2, N) {
        rep(j, 3) dp[i][j] = dp[i - 2][j] + A[i];
        if(i >= 3) {
            rep(j, 2) dp[i][j + 1] = max(dp[i][j + 1], dp[i - 3][j] + A[i]);
        }
    }
    ll ans = max(dp[N - 1][2], dp[N - 2][1]);
    if(N >= 3) ans = max(ans, dp[N - 3][0]);
    output(ans);
    return 0;
}
