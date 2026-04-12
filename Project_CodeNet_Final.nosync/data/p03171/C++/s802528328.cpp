#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    long long sum=0;
    vector<int> v(n);
    for(int&a : v){
        cin>>a;
        sum+=a;
    }
    vector<vector<long long>> dp(n+1,vector<long long>(n+1));
    for(int l=n-1;l>=0;l--){
        for(int r=l;r<n;r++){
            if(l==r) dp[l][r] = v[l];
            else dp[l][r]= max(v[l]-dp[l+1][r],v[r]-dp[l][r-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}