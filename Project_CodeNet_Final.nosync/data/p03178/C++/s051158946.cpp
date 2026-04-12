//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 200005
#define MOD 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string K; cin>>K;
    ll D; cin>>D;
    ll N = K.length();
    
    ll dp[N + 1][D][2];
    memset(dp,0,sizeof(dp));
    
    dp[0][0][1] = 1;
    
    for(ll i=0;i<N;++i)
    {
        for(ll j=0;j<D;++j)
        {
            for(ll d=0;d<=9;++d)
            {
                if(K[i] - '0' == d)
                {
                    //cout<<i + 1<<" "<<d<<endl;
                    dp[i + 1][(j + d) % D][1] += dp[i][j][1];
                    dp[i + 1][(j + d) % D][1] %= MOD;
                }
                else if(K[i] - '0' > d)
                {
                    dp[i + 1][(j + d) % D][0] += dp[i][j][1];
                    dp[i + 1][(j + d) % D][0] %= MOD;
                }

                dp[i + 1][(j + d) % D][0] += dp[i][j][0];
                dp[i + 1][(j + d) % D][0] %= MOD;
            }
        }
    }
    
    //cout<<dp[1][3][1]<<endl;
    
    cout<<(dp[N][0][0] + dp[N][0][1] - 1 + MOD) % MOD<<endl;
}