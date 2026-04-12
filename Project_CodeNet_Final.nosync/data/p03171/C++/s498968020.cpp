#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using Graph = vector<vector<int>>;

const int INF = 1 << 30;
const ll INFL = 1LL << 60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int N;
long long dp[3005][3005]; //---- dp[i][j]: a[i, j)を初期局面としたときのX-Y

int main(){
    cin >> N;
    vi a(N+1);
    rep(i,N) cin >> a[i];

    rep(i,N) dp[i][i] = 0; //---- 初期条件

    for(int len = 1; len <= N; ++len){
        for(int i = 0; i < N; ++i){
            int j = i + len;

            //---- 先手番
            if((N - len) % 2 == 0)
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);

            //---- 後手番
            else
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
        }
    }
    cout << dp[0][N];
    return 0;
}