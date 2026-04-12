#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

ll dp[200005][3];

int main()
{
    int n;
    cin >> n;
    int a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 2){
        cout << max(a[0], a[1]) << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++) dp[i][j] = -INF;
    }
    dp[1][0] = a[0];
    dp[2][1] = a[1];
    dp[3][2] = a[2];
    for(int i = 1; i <= n; i++){
        if(i >= 2){
            for(int j = 0; j < 3; j++){
                dp[i][j] = max(dp[i][j], dp[i - 2][j] + a[i - 1]);
            }
        }
        if(i >= 3){
            for(int j = 1; j < 3; j++){
                dp[i][j] = max(dp[i][j], dp[i - 3][j - 1] + a[i - 1]);
            }
        }
        if(i >= 4) dp[i][2] = max(dp[i][2], dp[i - 4][0] + a[i - 1]);
    }
    if(n % 2) cout << max(dp[n - 2][0], max(dp[n - 1][1], dp[n][2])) << endl;
    else cout << max(dp[n - 1][0], dp[n][1]) << endl;
}
