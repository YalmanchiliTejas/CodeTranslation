#include <iostream>

using namespace std;

long dp[3000][3000];


int main(){
    int N;
    long a[3000];
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++){
        if(N%2 == 0) dp[i][i] = -a[i];
        else dp[i][i] = a[i];
    }
    for(int i = 1; i < N; i++){
        for(int j = 0; j+i < N; j++){
            if((N-(i+1))%2 == 0){
                dp[j][j+i] = max(dp[j+1][j+i]+a[j], dp[j][j+i-1]+a[j+i]);
            }else{
                dp[j][j+i] = min(dp[j+1][j+i]-a[j], dp[j][j+i-1]-a[j+i]);
            }
        }
    }
    cout << dp[0][N-1] << endl;
}