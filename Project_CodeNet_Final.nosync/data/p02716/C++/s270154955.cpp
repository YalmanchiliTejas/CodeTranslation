#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    long long n, ans = 0, sum = 0;
    cin >> n;
    if(n == 1) {
        cin >> ans;
        cout << ans << endl;
        return 0;
    }
    vector<long long> a(n);
    if(n % 2 == 0) {
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(i % 2 == 1) sum += a[i];
        }
        ans = sum;
        for(int i = 0; i < n; i += 2) {
            sum = sum + a[i] - a[i+1];
            if(ans < sum) ans = sum; 
        }
        cout << ans << endl;
        return 0;
    }
    vector<vector<long long>> dp(n, vector<long long>(3, 0));
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = a[1];
    dp[0][2] = a[2];
    for(int i = 2; i < n-1; i += 2) {
        dp[i][0] = dp[i-2][0] + a[i];
        dp[i][1] = max({dp[i-2][0], dp[i-2][1]}) + a[i+1];
        dp[i][2] = max({dp[i-2][0], dp[i-2][1], dp[i-2][2]}) + a[i+2];
    }
    cout << max({dp[n-3][0], dp[n-3][1], dp[n-3][2]}) << endl;

    return 0;
}