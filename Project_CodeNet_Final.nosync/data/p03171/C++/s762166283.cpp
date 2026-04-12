#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
vector<int> arr;
vector<vector<ll>> dp;

ll solve(int x, int y){
    if(x > y) return 0;
    if(x == y) return arr[x];
    if(dp[x][y] != -1) return dp[x][y];
    ll u = solve(x+1, y);
    ll v = solve(x, y-1);
    return dp[x][y] = max(arr[x] - u, arr[y] - v);
}

int main(){
    cin>>n;
    arr.resize(n);
    dp.resize(n, vector<ll>(n, -1));
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    // ll res = solve(0, n-1);
    ll res;
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = arr[i];
            }else{
                dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1]);
            }
        }
    }
    res = dp[0][n-1];
    cout<<res<<endl;
    return 0;
}