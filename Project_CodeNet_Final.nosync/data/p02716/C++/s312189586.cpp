#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
#define ln '\n'
constexpr long long MOD = 1000000007LL;
//constexpr long long MOD = 998244353LL;
typedef long long ll;
typedef unsigned long long ull; 
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
template<class T, class U> inline bool chmax(T &a, U b) { if (a < b) { a = b; return true;} return false; }
template<class T, class U> inline bool chmin(T &a, U b) { if (a > b) { a = b; return true;} return false; }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<ll> A(N+1);
    rep(i,N) cin >> A[i+1];

    vector<ll> dp(N+1,-1e18);
    dp[0] = dp[1] = 0;
    vector<ll> O(N+5),E(N+5);
    for (int i = 1; i <= N; i++) {
        if (i&1) O[i+2] = O[i] + A[i];
        else E[i+2] += E[i] + A[i];
    }
    for (int i = 2; i <= N; i++) {
        if (i&1) {
            //cout << O[i+2] << ln;
            chmax(dp[i],O[i]);
            chmax(dp[i],dp[i-3]+A[i-1]);
            chmax(dp[i],dp[i-2]+A[i]);
        } else {
            chmax(dp[i],O[i+1]);
            chmax(dp[i],dp[i-2]+A[i]);
        }
        //cout << dp[i] << " ";
    }
    //cout << ln;

    cout << dp[N] << ln;
}


