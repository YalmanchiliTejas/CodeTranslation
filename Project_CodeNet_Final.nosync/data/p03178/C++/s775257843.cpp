//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

void add(ll &a,ll b)
{
    a = (a + b) % MOD;
}

int main()
{
    string K; cin>>K;
    ll D; cin>>D;
    ll N = K.length();
    
    ll dp[N][D][2]; //dp[i][j][k]: k tells whether (till i) there is some digit smaller than K[i]  
    memset(dp,0,sizeof(dp));
    
    //cout<<dp[1][0][1]<<endl;
    
    //base case
    dp[0][(K[0] - '0') % D][1] = 1;
    for(ll i=0;i<(K[0] - '0');++i)
        dp[0][i%D][0]++;
    
    //cout<<dp[0][0][0]<<endl;
    
    for(ll i=1;i<N;++i)
    {
        for(ll s=0;s<D;++s)
        {
            //cout<<"For: "<<i<<" "<<s<<" "<<endl;
            for(ll d = 0;d<10;++d)
            {
                if(K[i] - '0' == d)
                    add(dp[i][s][1],dp[i - 1][(s - d%D + D) % D][1]);
                else if(K[i] - '0' > d)
                    add(dp[i][s][0],dp[i - 1][(s - d%D + D) % D][1]);
                    
                add(dp[i][s][0],dp[i - 1][(s - d%D + D) % D][0]);
            }
            
            
        }
    }
    
    cout<<((dp[N - 1][0][0]%MOD + dp[N - 1][0][1]%MOD - 1 + MOD) % MOD)<<endl;
}