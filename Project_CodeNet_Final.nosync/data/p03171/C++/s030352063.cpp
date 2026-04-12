#include <iostream>

int a[3003];
long long dp[3003][3003];

int main(){
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for(int len = 1; len <= n; len++){
        for(int i = 0; i + len <= n; i++){
            int j = i + len;
            if((n-len)%2 == 0){
                dp[i][j] = std::max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }else{
                dp[i][j] = std::min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }
    std::cout << dp[0][n] << std::endl;
}
