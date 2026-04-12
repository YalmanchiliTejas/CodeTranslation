#include<bits/stdc++.h>
using namespace std;

const long long maxn = 3e3 + 10;
const long long mod = 998244353;

long long ans;
long long n, s;
long long a[maxn];
long long sum[maxn];
long long dp[maxn][maxn];

void in();
void solve();
void out();

int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    in();
    solve();
    out();
}

void in(){
    cin >> n >> s;
    for(long long i = 0; i < n; i++)
        cin >> a[i];
}

void solve(){
    dp[0][0] = 1;
    for(long long i = 1; i <= n; i++){
        for(long long j = 0; j <= s; j++){
            dp[i][j] = dp[i - 1][j];
            if(j - a[i - 1] >= 0)
                dp[i][j] += dp[i - 1][j - a[i - 1]];
            dp[i][j] %= mod;
        }
    }
    for(long long i = 0; i <= s; i++){
        for(long long j = 0; j <= n; j++){
            sum[i] += dp[j][i];
            sum[i] %= mod;
        }
    }
    for(long long i = 0; i < n; i++){
        ans += sum[s];
        ans %= mod;
        sum[0]--;
        for(long long j = 1; j <= s; j++){
            if(j - a[i] >= 0){
                sum[j] = (sum[j] - sum[j - a[i]] + mod) % mod;
            }
        }
    }
}

void out(){
    cout << ans;
}
