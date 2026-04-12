// https://atcoder.jp/contests/dp/tasks/dp_l

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0;i<n;i++)
        cin >> a[i];
    long long int dp[n][n] = { 0 };
    dp[n-1][n-1] = a[n-1];
    for(int i = n-2;i>=0;i--){
        for(int j =0;j<n;j++) {
            if(j < i){
                dp[i][j] = 0.0;
            }
            if(j == i){
                dp[i][j] = a[i];
            }
            if(j > i){
                dp[i][j] = max(a[j]-dp[i][j-1], a[i]-dp[i+1][j]);
            }
        }
    }
    // for(int i = 0;i<n;i++) {
    //     for(int j = 0;j<n;j++){
    //         cout <<dp[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    cout << setprecision(10) << dp[0][n-1]  << endl;

}