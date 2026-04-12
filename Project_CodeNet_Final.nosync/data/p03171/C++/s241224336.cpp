#include <bits/stdc++.h>

using namespace std;

long long dp[3005][3005];
long long arr[3005];

int main(){
    int N;
    cin >> N;
    for(int i = 1; i<=N; i++){
        cin >> arr[i];
    }
    for(int le = 1; le<=N; le++){
        for(int l = 1; l+le-1 <= N; l++){
            int r = l+le-1;
            if(N%2 == le%2){
                dp[l][r] = max(dp[l+1][r] + arr[l], dp[l][r-1] + arr[r]);
            }
            else{
                dp[l][r] = min(dp[l+1][r] - arr[l], dp[l][r-1] - arr[r]);
            }
        }
    }
    cout << dp[1][N] << endl;
}
