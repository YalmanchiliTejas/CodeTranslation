#include<iostream>
#include<vector>

int main(){
    int n;
    std:: cin >> n;
    std:: vector<long long>arr(n+1,0);
    for(int i = 0; i < n; i++){
        std:: cin >> arr[i];
    }

    long long dp[n+2][n+2] = {0};

    for(int i = n-1; i >= 0; i--) 
    {
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = arr[i];
            }
            else
            {
                dp[i][j] = std::max(arr[i]-dp[i+1][j], arr[j]-dp[i][j-1]);
            }
        }
    }

    std::cout << dp[0][n-1];
    return 0;
}