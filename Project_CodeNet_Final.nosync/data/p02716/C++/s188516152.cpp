#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N, 0);
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }
    vector<vector<ll>> dp(N, vector<ll>(3, LLONG_MIN));
    for(int i=0;i<N;i++){
        if(i==0){
            dp[i][0] = A[i];
            dp[i][1] = 0ll;
            dp[i][2] = 0ll;
        }else if(i==1){
            dp[i][0] = 0ll;
            dp[i][1] = A[i];
            dp[i][2] = 0ll;
        }else if(i==2){
            dp[i][0] = dp[i-2][0] + A[i];
            dp[i][1] = dp[i-2][1] + A[i];
            dp[i][2] = dp[i-2][2] + A[i];
        }else if(i==3){
            dp[i][0] = dp[i-2][0] + A[i];
            dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + A[i];
            dp[i][2] = max(dp[i-2][2], dp[i-3][1]) + A[i];
        }else{
            dp[i][0] = dp[i-2][0] + A[i];
            dp[i][1] = max(dp[i-2][1], dp[i-3][0]) + A[i];
            dp[i][2] = max(dp[i-2][2], max(dp[i-3][1], dp[i-4][0])) + A[i];
        }
    }
    if(N % 2 == 0){
        cout << max(dp[N-1][1], dp[N-2][0]) << endl;
    }else{
        cout << max(dp[N-1][2], max(dp[N-2][1], dp[N-3][0])) << endl;
    }
    return 0;
}
