#include <bits/stdc++.h>
using namespace std;

long long dp[3100][3100];

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    fill(dp[0], dp[N], 0);
    
    for (int k = 1; k <= N; k++) {
        for (int i = 0; i + k <= N; i++) {
            int j = i + k;
            
            if((N-k)%2==0){
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
            }else{
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
            }
        }
    }

    cout << dp[0][N] << endl;
}