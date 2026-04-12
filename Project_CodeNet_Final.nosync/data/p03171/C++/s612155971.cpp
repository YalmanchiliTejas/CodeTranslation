/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;


ll foo(ll arr[], int n) {
    int i = 0;
    int j = 0;
    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>> (n, {0, 0}));
    while (i < n && j < n) {
        dp[i][j] = {arr[i], 0};
        i++;
        j++;
    }
    for (int k = 1; k < n; k++) {
        i = 0;
        j = k;
        while (i < n && j < n) {
            pair<ll, ll> p1, p2;
            p1.first = arr[j] + dp[i][j-1].second;
            p1.second = dp[i][j-1].first;
            p2.first = arr[i] + dp[i+1][j].second;
            p2.second = dp[i+1][j].first;
            if (p1.first - p1.second > p2.first - p2.second) {
                dp[i][j] = p1;
            } else {
                dp[i][j] = p2;
            }
            i++;
            j++;
        }
    }
    return dp[0][n-1].first - dp[0][n-1].second;
}

int main()
{
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << foo(arr, n);
    return 0;
}


