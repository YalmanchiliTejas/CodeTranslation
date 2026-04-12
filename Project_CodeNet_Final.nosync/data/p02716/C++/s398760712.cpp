#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int yo;
    if (N % 2) yo = 3;
    else yo = 2;
    vector<vector<ll>> dp(N + 1, vector<ll>(yo, -1e16));
    for (int i = 0; i < yo; i++) dp[i + 1][i] = a[i];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < yo; j++) {
            for (int k = 0; k < yo; k++) {
                if (i + 2 + k > N || j + k >= yo) {
                    continue;
                }
                dp[i + 2 + k][j + k] = max(dp[i + 2 + k][j + k], dp[i][j] + a[i + 1 + k]);
            }
        
        }
    }
    ll ans = -1e16;
    for (int i = 0; i < yo; i++) {       
        ans = max(ans, dp[N-(yo-1)+i][i]);
    }
    cout << ans << endl;
}
