#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD_VAL = 1e9+7;
ll dp[10005][105];
string k;
int d;

int main(){
    int sum = 0;
    cin>>k>>d;
    int len = k.length();
    for(int i=0;i<len;i++){
        int val = k[i] - '0';
        sum += val;
        if(i!=0)
            for(int j=0;j<d;j++){
                for(int z=0;z<=9;z++) {
                    dp[i][(j + z) % d] += dp[i - 1][j];
                    dp[i][(j + z) % d] %= MOD_VAL;
                }
            }
        for(int j=0;j<val;j++){
            dp[i][(sum-val+j)%d]++;
            dp[i][(sum-val+j)%d] %= MOD_VAL;
        }
    }
    cout<<(MOD_VAL + dp[len-1][0]-1+(sum % d == 0))%MOD_VAL;
    return 0;
}