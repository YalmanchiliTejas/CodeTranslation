#include <bits/stdc++.h>

using namespace std;

string k;
int d;
int dp[10010][2][100];
const int MOD = 1e9 + 7;

int f(int pos, bool flag, int mod){
    if(pos == k.size()){
        if(mod == 0) return 1;
        else return 0;
    }

    int &ret = dp[pos][flag][mod];

    if(ret != -1) return ret;

    ret = 0;

    int mx = k[pos] - '0';

    if(!flag) mx = 10;

    for(int i = 0; i < mx; i++){
        ret = (ret + f(pos + 1, false, (mod + i) % d)) % MOD;
    }

    if(flag) ret = (ret + f(pos + 1, true, (mod + mx) % d)) % MOD;

    return ret;
}

int main(){
    getline(cin, k);
    scanf("%d", &d);

    memset(dp, -1, sizeof(dp));

    printf("%d\n", (f(0, true, 0) + MOD - 1) % MOD);
    
    return 0;
}