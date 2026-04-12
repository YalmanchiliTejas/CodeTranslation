#include <iostream>

using namespace std;

long dp[400][200][200];

int main(){
    int H, W;
    long a[200][200];
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> a[i][j];
        }
    }
    dp[0][0][0] = a[0][0];
    for(int i = 1; i <= H+W-2; i++){
        for(int j = 0; j < W; j++){
            if(i-j < 0 || i-j >= H) continue;
            for(int k = 0; k < W; k++){
                if(i-k < 0 || i-k >= H) continue;
                if(j > 0 && k > 0) dp[i][j][k] = dp[i-1][j-1][k-1];
                if(i-j-1 >= 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                if(i-k-1 >= 0 && j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k]);
                if(i-j-1 >= 0 && i-k-1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                               
                if(j == k) dp[i][j][k] += a[i-j][j];
                else dp[i][j][k] += (a[i-j][j]+a[i-k][k]);
                //cout << i <<  ' ' << j <<  ' ' << k << ' ' << dp[i][j][k] << endl;
            }
        }
    }
    cout << dp[H+W-2][W-1][W-1] << endl;
}