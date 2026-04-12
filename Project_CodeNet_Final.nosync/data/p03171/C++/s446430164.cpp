#include <bits/stdc++.h>

#define CEIL(a,b) ((a) / (b) + ((a) % (b) == 0 ? 0 : 1))

using namespace std;
using ll = long long;
using pii = pair<int, int>;

constexpr int MOD = 1'000'000'007;
constexpr int INF = 1'000'000'001;
constexpr ll LLINF = 4'000'000'000'000'000'001;
// constexpr int INF = 2147483647; // 2 * 1e9
// constexpr ll LLINF = 9223372036854775807; // 9 * 1e18

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

vector<int> a, dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    a = vector<int>(n+1);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n)); //dp[i][j] := [a[i], a[j]]でゲームをしたときのX-Yの値
    for(int i = n-1; i >= 0; --i){
        for(int j = i; j < n; ++j){
            if((n-i-j+1) % 2 == 0){ //Fst
                dp[i][j] = -LLINF;
                if(i+1 < n)dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j]);
                if(j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + a[j]);
                if(n == 1) dp[0][0] = a[0];
            }
            else{// Snd
                dp[i][j] = LLINF;
                if(i+1 < n)dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j]);
                if(j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j-1] - a[j]);
            }
        }
    }

    cout << dp[0][n-1] << "\n";

    return 0;
}