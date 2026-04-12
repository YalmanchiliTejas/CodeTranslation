#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
#define ll long long
ll dp[100][100001];


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string k;
    int d;
    cin>>k;
    cin>>d;
    memset(dp, 0,  sizeof(dp));
    for(int i = 0 ; i < 10 && i <  (k[0] - '0') ; i++){
        dp[i%d][0] += 1;
        dp[i%d][0]  = dp[i%d][0]%mod;
    }
    long long pre = 0;
    for(long long j = 0 ;  j < k.size() - 1 ; j++){
        pre += (k[j] - '0');
        pre = pre%d;
        for(int i = 0 ; i < d; i++){
            for(int x = 0; x < 10 ; x++){
                long long z = i + x;
                dp[z%d][j + 1] += dp[i][j];
                dp[z%d][j + 1] = dp[z%d][j + 1]%mod;
            }
        }
        for(int x = 0 ; x < (k[j+1] - '0') ; x++){
            long long z = pre + x;
            dp[z%d][j + 1] += 1;
            dp[z%d][j + 1] = dp[z%d][j + 1]%mod;
        }
    }
    // for(int i = 0 ; i < d ; i++){
    //     for(int j = 0 ; j < k.size() ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    pre += (k[k.size() -1]-'0');
    pre = pre%d;
    if(pre == 0){
        cout<<(dp[0][k.size()-1])%mod<<endl;
    }else{
        cout<<((dp[0][k.size()-1] - 1) + mod)%mod<<endl;
    }
    return 0;
}
