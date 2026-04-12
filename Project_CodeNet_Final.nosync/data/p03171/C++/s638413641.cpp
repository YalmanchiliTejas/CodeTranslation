#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int n;
int arr[3001];

long long dp[3001][3001][2];
bool visited[3001][3001][2];

long long funct(int i, int j, bool mx) {

    if(i == j) {
        if(!mx) return -arr[i];
        return arr[i];
    }
    if(visited[i][j][mx]) {
        return dp[i][j][mx];
    }
    visited[i][j][mx] = 1;



    long long a = funct(i, j-1, mx^1);
    long long b = funct(i + 1, j, mx^1);
    if(mx) {
        dp[i][j][mx] = max(a + arr[j], arr[i] + b);
    } else {
        dp[i][j][mx] =  min(-arr[j] + a, -arr[i] + b);
    }

    return (dp[i][j][mx]);
}


int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    long long ans = funct(0, n-1, 1);
    // cout << dp[0][1][0] << " ";
    cout << ans ;
}