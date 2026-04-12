#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5, M = 105, MOD = (int)1e9+7;
string k;
int d, dp[N][M][2];

int solve(int idx, int rem, int less){
    int &res = dp[idx][rem][less];
    if(idx == k.size())
        return rem == 0;
    if(res != -1)
        return res;
    res = 0;
    for(int i = 0; i <= ((less)? 9 : (int)(k[idx] - '0')); ++i){
        res += solve(idx + 1, (rem + i) % d, less | (k[idx] - '0') > i);
        res %= MOD;
    }
    return res;
}

int main(){
    cin >> k >> d;
    int n = k.size();
    memset(dp, -1, sizeof(dp));
    cout << (solve(0, 0, 0) - 1 + MOD) % MOD;
}
