#include <bits/stdc++.h>
using namespace std;
#define ll long long 

ll calc(vector<vector<ll>> &dp, vector<ll> &in, int start, int end){
    if(start > end){
        return 0;
    }
    if(dp[start][end] != -1){
        return dp[start][end];
    }
    if(start == end){
        return dp[start][end] = in[start];
    }
    return dp[start][end] = max(in[start] - calc(dp, in, start + 1, end), in[end] - calc(dp, in, start, end - 1));
}



int main(){
    ll n;
    cin>>n;
    vector <ll> in(n);
    for(auto &it : in){
        cin>>it;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    cout<<calc(dp, in, 0, n - 1);
    return 0;
}