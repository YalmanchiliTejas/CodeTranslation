#include <bits/stdc++.h>

using namespace std;

long long dp[10005][105];
int v[10005];
string s;
long long MOD = 1000000007;
int N, K;

int main(){
    cin >> s >> K;
    N = s.size();
    for(int i = 1; i<=N; i++){
        v[i] = s[N-i] - '0';
    }
    dp[0][0] = 1;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<K; j++){
            for(int d = 0; d<=9; d++){
                dp[i][(j+d)%K] += dp[i-1][j];
                dp[i][(j+d)%K] %= MOD;
            }
        }
    }
    int sum = 0;
    long long res = 0;
    for(int i = N; i>=1; i--){
        for(int j = 0; j < v[i]; j++){
            res += dp[i-1][((-(sum+j))%K + K)%K];
            res %= MOD;
        }
        sum += v[i];
    }
    if(sum%K){
        res = (res+MOD-1)%MOD;
    }
    cout << res << endl;
}
