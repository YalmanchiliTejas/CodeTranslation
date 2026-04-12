#include <bits/stdc++.h>
using namespace std;

const int64_t MOD = 1e9+7;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

string K;
int D, N;

int64_t dp[10001][100][2];

int64_t rec(int d, int r, bool less){
    if(d >= N) return (r==0);
    if(dp[d][r][less] >= 0) return dp[d][r][less];
    int64_t result = 0;
    for(int k=0; k<=(less ? 9 : K[d] - '0'); k++){
        add(result, rec(d+1, (r+k)%D, less | (k < K[d]-'0')));
    }
    dp[d][r][less] = result;
    return result;
}

int main(){
    cin >> K >> D;
    N = K.size();
    memset(dp, -1, sizeof(dp));
    cout << (rec(0, 0, 0) + MOD - 1) % MOD << endl;
    return 0;
}