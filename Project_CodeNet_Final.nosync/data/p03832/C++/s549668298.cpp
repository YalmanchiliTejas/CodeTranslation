#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007

int n, a, b, c, d;

int kai[1010];
int memo[1010][1010];

void init(){
    kai[0] = 1;
    for(int i = 1;i < 1010;i++){
        kai[i] = (kai[i-1] * i) % MOD;
    }
}

int pow_mod(int n, int m){
    int ans = 1;

    while(m > 0){
        if(m & 1) ans = (ans * n) % MOD;
        n = (n * n) % MOD;
        m >>= 1;
    }

    return ans;
}


int cmemo[1010][1010];

int combi(int n, int r){
    if(cmemo[n][r] != -1) return cmemo[n][r];
    return cmemo[n][r] = ((kai[n] * pow_mod(kai[r], MOD-2) % MOD) * pow_mod(kai[n-r], MOD-2)) % MOD;}

int memo2[1010][1010] = {};

int dp(int i, int j){
    if(j == 0) return 1;
    if(i > b)  return 0;
    if(memo[i][j] != -1) return memo[i][j];

    int ans = dp(i+1, j);

    int tmp = 1;
    int tt = j;
    int tt2 = 1;
    int cnt = 1;

    for(int num = 1;num < c;num++){
        tt -= i;
        if(tt < 0) return memo[i][j] = ans;
        tt2 = (tt2 * cnt) % MOD;
        cnt++;
        tmp = (tmp * combi(tt+i, i)) % MOD;
    }

    for(int num = c;num <= d;num++){
        tt -= i;
        tt2 = (tt2 * cnt) % MOD;
        cnt++;
        if(tt < 0) return memo[i][j] = ans;
        tmp = (tmp * combi(tt+i, i)) % MOD;
        ans = (ans + (dp(i+1, j-num*i) * (tmp*pow_mod(tt2, MOD-2) % MOD)) % MOD) % MOD;
    }

    return memo[i][j] = ans;
}

signed main(){

    init();

    cin >> n >> a >> b >> c >> d;

    memset(memo, -1, sizeof(memo));
    memset(cmemo, -1, sizeof(cmemo));

    cout << dp(a, n) << endl;

    return 0;
}
