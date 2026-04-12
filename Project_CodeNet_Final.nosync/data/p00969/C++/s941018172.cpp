#include <iostream>
#include <algorithm>
using namespace std;

int n;
int v[5000];
int dp[5000][5000];    //dp[i][j] = {～, v[i], v[j]}, max-cnt

void chmax(int &a, int b) {
    a = max(a, b);
}

int main() {
    int i, j;
    
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            dp[i][j] = 2;
        }
    }
    
    for (j = 1; j < n; j++) {
        for (i = 0; i < j; i++) {
            int d = v[j] - v[i];
            int val = v[j] + d;
            int index = lower_bound(v + j, v + n, val) - v;
            if (index < n && v[index] == val) {
                chmax(dp[j][index], dp[i][j] + 1);
            }
        }
    }
    
    int ans = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            chmax(ans, dp[i][j]);
        }
    }
    
    cout << ans << endl;
    return 0;
}
