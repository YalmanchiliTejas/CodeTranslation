#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<vector<ll>> dp(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        if (N%2 == 1) dp[i][i] = A[i];
        else dp[i][i] -= A[i];
    }
    
    for (int l = 2; l <= N; l++) {
        for (int i = 0; i+l-1 <= N-1; i++) {
            if ((N-l)%2 == 0) dp[i][i+l-1] = max(dp[i+1][i+l-1]+A[i], dp[i][i+l-2]+A[i+l-1]);
            else dp[i][i+l-1] = min(dp[i+1][i+l-1]-A[i], dp[i][i+l-2]-A[i+l-1]);
        }
    }
    
    cout << dp[0][N-1] << endl;
    return 0;
}