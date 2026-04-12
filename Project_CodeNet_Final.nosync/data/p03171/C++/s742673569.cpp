#include <bits/stdc++.h>
using namespace std;

#define PI pair<long long, long long >

long long game(vector<int> v, int n){
    vector<vector<PI>> dp(n, vector<PI>(n));
    for(int i=0; i<n; i++) dp[i][i].first = v[i], dp[i][i].second = 0;
    for(int l=2; l<=n; l++){
        for(int i=0; i<=(n-l); i++){
            int j=i+l-1;
            if(v[i]+dp[i+1][j].second > v[j]+dp[i][j-1].second){
                dp[i][j].first = v[i]+dp[i+1][j].second;   
                dp[i][j].second = dp[i+1][j].first;
            }else{
                dp[i][j].first = v[j]+dp[i][j-1].second;   
                dp[i][j].second = dp[i][j-1].first;
            }    
        }
    }
    return dp[0][n-1].first-dp[0][n-1].second;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<game(v, n);
    return 0;
}
