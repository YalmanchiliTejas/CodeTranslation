#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(false);
    
    int n; cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    vector<vector<long long>>dp(n, vector<long long>(n));

    for(int i = 0; i < n; i++){
        dp[i][i] = v[i];
    }

    for(int i = 2; i <=n; i++){
        for(int j = n-i; j >= 0; j--){
            dp[j][j+i-1] = max(v[j]-dp[j+1][j+i-1], v[j+i-1]-dp[j][j+i-2]);
        }
    }

    cout<<dp[0][n-1]<<endl;
}
