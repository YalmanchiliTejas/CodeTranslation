#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
const double PI = acos(-1);
const ll MOD = 1000000007;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
 
template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
///////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    vector<vector<ll>> dp(N, vector<ll>(N));
    rep(i,N) dp[i][i] = a[i];
    for (int k = 1; k < N; k++) {
        rep(i,N-k) {
            dp[i][i+k] = max(a[i]-dp[i+1][i+k],a[i+k]-dp[i][i+k-1]);
        }
    }

    cout << dp[0][N-1] << endl;
}
