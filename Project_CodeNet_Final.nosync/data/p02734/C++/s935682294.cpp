#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main() {
    int N,S;
    cin>>N>>S;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<vector<long long int>> dp(N,vector<long long int>(S+1));
    dp[0][0]=1;
    if(A[0]<S+1)dp[0][A[0]]=1;
    for (int i = 1; i < N; i++){
        dp[i][0]=1;
        for (int j = 1; j < S+1; j++){
            if(j-A[i]>0)dp[i][j]=(dp[i-1][j]+dp[i-1][j-A[i]])%MOD;
            else if(j-A[i]==0)dp[i][j]=(dp[i-1][j]+i+1)%MOD;
            else dp[i][j]=dp[i-1][j];
        }
    }
    int ans=0;
    for (int i = 0; i < N; i++){
        ans+=dp[i][S];
        ans%=MOD;
    }
    cout <<ans<<endl;
}