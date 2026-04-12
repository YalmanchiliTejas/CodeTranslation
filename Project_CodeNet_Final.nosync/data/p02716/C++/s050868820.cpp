#include<iostream>
using namespace std;

int main(){
    long long N;
    cin >> N;
    long long A[N+1];
    long long i;
    long long oddsum[N+1];
    for(i = 1; i <= N; i++){
        cin >> A[i];
    }
    oddsum[1] = A[1];
    for(i = 3; i <= N; i += 2){
        oddsum[i] = oddsum[i-2] + A[i];
    }
    long long dp[N];
    dp[2] = max(A[1],A[2]);
    if(N>=3){
        dp[3] = max(dp[2],A[3]);
    }
    if(N>=4){
        dp[4] = max(A[1]+A[3],A[1]+A[4]);
        dp[4] = max(dp[4], A[2]+A[4]);
    }
    for(i = 5; i <= N; i++){
        if(i % 2 == 0){
            dp[i] = max(dp[i-2]+A[i],oddsum[i-1]);
        }else{
            dp[i] = max(dp[i-2]+A[i],dp[i-3]+A[i-1]);
            dp[i] = max(dp[i],oddsum[i-2]);
        }
    }
    cout << dp[N] << endl;
    system("pause");
    return 0;
}