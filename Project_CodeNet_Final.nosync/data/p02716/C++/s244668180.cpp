#include<bits/stdc++.h>
#define enld '\n'
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    int k = 1 + N%2;
    vector<vector<ll>> dp(N+1, vector<ll> (4,-INF));
    dp[0][0] = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<k+1; j++){
            chmax(dp[i+1][j+1],dp[i][j]);
            ll now = dp[i][j];
            if((i+j)%2 == 0) now += A[i];
            chmax(dp[i+1][j],now);
        }
    }
    cout << dp[N][k] << enld;
    return 0;
}