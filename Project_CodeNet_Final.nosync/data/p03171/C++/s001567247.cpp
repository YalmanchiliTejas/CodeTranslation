//============================================================================
// Name        : ProjG.cpp
// Author      : Yong Kiat
// Version     :
// Copyright   : By Algotae.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

const int mxN=3000;
int n, a[mxN];
long long dp[mxN+1][mxN+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
    	for (int j = i - 1; j >= 0; j--) {
    		dp[i][j] = max(a[i-1] - dp[i-1][j], a[j] - dp[i][j+1]);
    	}
    }

    cout << dp[n][0];
}
