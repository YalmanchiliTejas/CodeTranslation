#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
void solve(vector<int64> &A){
    int n = A.size();
    int64 dp[n + 1][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            dp[i][j] = 0;
        }
    }
    dp[2][1] = A[2];
    dp[2][0] = A[1];
    for(int i = 3; i < n; i++){
        if(i % 2 == 1){ // odd.
            dp[i][0] = max(A[i - 1] + dp[i - 2][0],
                       max(A[i - 1] + dp[i - 3][0],
                       max(A[i - 1] + dp[i - 3][1],
                           A[i - 2] + dp[i - 3][0])));
            dp[i][1] = A[i] + max(dp[i - 2][0],
                              max(dp[i - 2][1],
                              max(dp[i - 3][1],
                                  dp[i - 3][1])));
        }
        else{
            dp[i][0] = A[i - 1] + dp[i - 2][0];
            dp[i][1] = A[i] + max({dp[i - 1][0],
                                   dp[i - 2][0],
                                   dp[i - 2][1]});
        }
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    return;
}
int main(){
    int n; cin >> n;
    vector<int64> A(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }
    solve(A);
    return 0;
}
