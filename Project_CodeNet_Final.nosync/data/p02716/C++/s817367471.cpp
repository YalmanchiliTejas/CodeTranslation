#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    long long dp[n];
    dp[0] = 0;
    dp[1] = max(arr[0], arr[1]);
    long long pre[n];
    pre[0] = arr[0];
    for(int i = 2; i<n; i+=2) pre[i] = pre[i-2]+arr[i];
    for(int i = 2; i<n; i++){
        if(i % 2 == 0){
            dp[i] = max(arr[i]+dp[i-2], dp[i-1]);
        }
        else{
            dp[i] = max(arr[i]+dp[i-2], pre[i-1]);
        }
    }
    cout << dp[n-1] << endl;
}