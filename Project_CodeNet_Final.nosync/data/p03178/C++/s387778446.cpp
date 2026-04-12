// Created by sz
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7, maxn = 1e4+5;
string K;
int D, dp[maxn][105][2];

int main(){
#ifdef LOCAL
    freopen("./input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>K>>D;

    dp[0][0][0] = 1;
    for(int i=0;i<K.length();i++){
        int dig = K[i]-'0';
        for(int j=0; j<D; j++){
            for(int a=0; a<=dig;a++){
                if(a == dig) (dp[i+1][(j+a)%D][0] += dp[i][j][0])%=mod;
                else (dp[i+1][(j+a)%D][1] += dp[i][j][0])%=mod;
            }
            for(int a=0; a<=9;a++){
                (dp[i+1][(j+a)%D][1] += dp[i][j][1])%=mod;
            }
        }
    }
    long long  ans = -1LL+dp[K.length()][0][0]+dp[K.length()][0][1];

    cout<<(ans%mod+mod)%mod<<endl;
    return 0;
}

