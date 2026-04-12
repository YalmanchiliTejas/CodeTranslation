#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using P = pair<int, int>;
using P3 = pair<P,ll>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ll MOD = 998244353;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
constexpr double EPS = 1e-9;

int main(){
    int N, S;
    cin >> N >> S;
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    ll ans = 0;
    vector<vector<ll> > dp(N+1, vector<ll>(S+1));
    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            if(j<S) dp[i+1][j] = dp[i][j];
            if(j>=a[i]){
                if(j==a[i]) dp[i+1][j] += i+1;
                else dp[i+1][j] += dp[i][j-a[i]];
            }
            dp[i+1][j] %= MOD;
        }
    }
    for(int i=0;i<=N;i++){
        ans += dp[i][S]*(N-i+1);
        ans %= MOD;
    }
    cout << ans << endl;
}
