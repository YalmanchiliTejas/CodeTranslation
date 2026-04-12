#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int solve(int l, int r, vector<long long int>&v, vector<vector<long long int>>&dp){
    if(l==r)
        return v[l];
    else{
        if(dp[l][r]!=-1)
            return dp[l][r];

        return dp[l][r]=max((v[l]-solve(l+1, r, v, dp)), (v[r]-solve(l, r-1, v, dp)));
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<long long int>v(n);
    vector<vector<long long int>>dp(n, vector<long long int>(n, -1));
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    cout<<solve(0, n-1, v, dp);
    return 0;
}
