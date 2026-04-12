//
// Created by ss250251 on 2/16/2020.
//

#include<bits/stdc++.h>
using namespace std;
#define INF 1e18L + 7
#define MOD 1e9+7
template <typename T>
void max_self(T&a,T b){
    a = max(a,b);
}
template <typename T>
void min_self(T&a,T b){
    a = min(a,b);
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(i==j)dp[j][i]=a[i];
            else{
                dp[i][j] = max(a[j]-dp[i][j+1], a[i] - dp[i-1][j]);
            }
        }
    }
    cout<<dp[n-1][0];
}