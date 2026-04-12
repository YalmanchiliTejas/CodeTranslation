#include<bits/stdc++.h>

int main(){
    constexpr long long mod=998244353;
    int N,S;std::cin>>N>>S;
    using ll = long long;
    std::vector<std::vector<std::vector<ll>>> dp(N+1,std::vector<std::vector<ll>>(S+1,std::vector<ll>(3)));
    std::vector<int> A(N);
    for(int i=0;i<N;++i) std::cin>>A[i];
    dp[0][0][0]=1;
    for(int i=0;i<N;++i) for(int s=0;s<=S;++s){
        dp[i+1][s][0]=dp[i][s][0];
        dp[i+1][s][1]=dp[i][s][1];
        dp[i+1][s][2]=dp[i][s][2];
        if(s>=A[i]){
            dp[i+1][s][1]+=(i+1)*dp[i][s-A[i]][0]+dp[i][s-A[i]][1];
            dp[i+1][s][2]+=(N-i)*dp[i][s-A[i]][1]+(N-i)*(i+1)*dp[i][s-A[i]][0];
        }
        for(int j=0;j<3;++j) dp[i+1][s][j]%=mod;
    }
    std::cout<<dp[N][S][2]<<std::endl;
}