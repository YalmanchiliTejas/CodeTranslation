#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long int
int32_t main() {
    int n ;
    cin >> n ;
    int a[n];
    for(int i = 0 ; i <n ; i++){
        cin >> a[i]  ;
    }
    int dp[n][n];
    for(int len = 0 ; len <n ; len++){
        for(int start = 0 ; start < n -len ; start++){
            int end = start + len; 
            int t1 = (start+2 <= end)?dp[start+2][end]:0 ;
            int t2 = (start+1<= end-1)?dp[start+1][end-1]:0 ;
            int t3 = (start<=end-2)?dp[start][end-2]:0;
            dp[start][end] = max(a[start]+min(t1,t2),a[end]+min(t2,t3)) ;
        }
    }
    int total = 0;
    for(int i = 0 ; i <n ; i++){
        total = total + a[i];
    }
    cout << (2*dp[0][n-1] - total) << endl ;
    return 0;
}