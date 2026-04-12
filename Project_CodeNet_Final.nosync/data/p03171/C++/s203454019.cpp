#include <iostream>
using namespace std;

#define ll long long

ll sum(int i, int j, ll* sum) {
    if (i == 0)
        return sum[j];
    return sum[j] - sum[i-1];
}

int main() {
    int N; cin >> N;
    int arr[N];
    for (int i=0; i<N; i++) scanf("%d", arr+i);

    ll s[N];
    s[0] = arr[0];
    for (int i=1; i<N; i++) 
        s[i] = s[i-1] + arr[i];

    ll dp[2][N][N];
    for (int i=0; i<N; i++) 
        dp[0][i][i] = dp[1][i][i] = arr[i];

    for (int len=2; len<=N; len++) {
        for (int i=0; i+len-1<N; i++) {
            int j=i+len-1;

            dp[0][i][j] = sum(i,j, s) - min(dp[1][i+1][j], dp[1][i][j-1]);
            dp[1][i][j] = sum(i,j, s) - min(dp[0][i+1][j], dp[0][i][j-1]);

        }
    }

    cout << 2*dp[0][0][N-1] - s[N-1] << endl;

    return 0;
}