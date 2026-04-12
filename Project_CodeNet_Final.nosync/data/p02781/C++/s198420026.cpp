#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

const int MAX_K = 3;

ll dp[100][3+1];

int main(){
    string N;
    cin >> N;
    long long K;
    scanf("%lld",&K);

    int d = N.length();

    dp[0][0]=1;

    for(int i=1; i<d; i++) {
        for (int j=3; j>=0; j--) {
            dp[i][j] = dp[i-1][j] + (j ? 9*dp[i-1][j-1] : 0);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    ll ans = 0;
    for(int i=0; i<d && K>=0; i++) {
        int a = N[i] - '0';
        if (a > 0) {
            ans += K ? dp[d-i-1][K] : 0;
            ans += K ? (a-1)*dp[d-i-1][K-1] : 0;
            K--;
        }
    }
    if (K <= 0) ans++;
    cout << ans << endl;
    return 0;
}
