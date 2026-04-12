#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
using ll = long long;
const int N = 2e5+10;
ll arr[N];
ll dp[N][2][2];
int n;
int main() {
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> arr[i];
    for(int i = 1; i <= n; i ++) {
        if(i & 1) {
            dp[i][0][0] = dp[i-1][1][0] + arr[i];
            dp[i][0][1] = arr[i] + dp[i-1][1][1];
            dp[i][1][1] = max(dp[i-1][1][0], dp[i-1][0][0]);
        } else {
            dp[i][0][0] = arr[i] + dp[i-1][1][1];
            dp[i][1][0] = dp[i-1][0][0];
            dp[i][1][1] = max(dp[i-1][0][1], dp[i-1][1][1]);
            //cout << i << " "<<dp[i][0][0]<<"-" <<dp[i][1][0]<<"-"<<dp[i][1][1]<< endl;
        }

    }
    if(n & 1) {
        cout << max(dp[n][0][1], dp[n][1][1]) << endl;
    } else {
        cout << max(dp[n][1][0], dp[n][0][0]) << endl;
    }
    return 0;
} 