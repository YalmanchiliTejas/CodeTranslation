#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;



string k;
int D;
int dp[10001][101][2];

long long dfs(int pos, int d, int lower){
    if( pos == k.size() ) return d == 0;
    if( dp[pos][d][lower] != -1) return dp[pos][d][lower];

    long long ans = 0;
    if( lower ){
        for(int i = 0 ; i < 10 ; i++){
            ans += dfs(pos+1, (d+i) % D, true);
        }
    }else{
        for(int i = 0 ; i < k[pos] - '0' ; i++){
            ans += dfs(pos+1, (d+i) % D, true);
        }
        ans += dfs(pos+1, (d+k[pos]-'0') % D, false);
    }

    return dp[pos][d][lower] = ans % MOD;
}
void solve(string K, long long D){
    k = K;
    ::D = D;
    memset(dp, -1, sizeof(dp));
    cout << (dfs(0, 0, 0) - 1 + MOD) % MOD << endl;
}

int main(){
    string K;
    cin >> K;
    long long D;
    scanf("%lld",&D);
    solve(K, D);
    return 0;
}
