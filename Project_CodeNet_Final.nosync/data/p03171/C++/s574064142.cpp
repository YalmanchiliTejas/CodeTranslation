#include<bits/stdc++.h>
#include<thread>
#define ll long long
#define ld long double
#define pi acos(-1)
#define mod 1000000007
#define show(x, y); cout << x << " " << y << endl;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll dp[n][n];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++){
        dp[i][i] = a[i];
    }
    for(int len = 1; len < n; len++){
        for(int i = 0, j = i + len; j < n; i++, j++){
            dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];
}
