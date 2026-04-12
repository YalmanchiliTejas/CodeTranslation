#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){ 
    string s; int K; cin >> s >> K;
    int len = s.size();
    int dp[110][2][5];
    rep(i, 110){rep(j, 2){rep(k, 5){dp[i][j][k] = 0;}}};

    dp[0][0][0] = 1;

    rep(i, len){
        int n = s[i] - '0';
        rep(smaller, 2){
            rep(k, 4){    
                for(int x = 0; x <= (smaller ? 9 : n); x++){
                    dp[i+1][smaller || x < n][x != 0 ? k+1 : k] += dp[i][smaller][k];
                }
            }
        }
    }
    cout << dp[len][0][K] + dp[len][1][K] << ln;
}