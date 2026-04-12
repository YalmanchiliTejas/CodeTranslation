#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll func(ll st, ll en, vector<vector<ll>>&dp, vector<ll>&arr){
    if(st>en)return 0;
    if(dp[st][en]!=-1){
        return dp[st][en];
    }
    dp[st][en] = max(arr[st]+ min(func(st+2, en, dp, arr), func(st+1, en-1, dp, arr)), arr[en] + min(func(st+1, en-1, dp, arr), func(st, en-2, dp, arr)));
    return dp[st][en];
}

int main(){
    ll t;
    t = 1;
    while(t--){
        ll n;
        cin>>n;
        ll sum = 0;
        vector<ll>arr(n, 0);
        for(ll i =0 ; i < n ; i++){
            cin>>arr[i];
            sum+=arr[i];
        }
        vector<vector<ll>>dp(n, vector<ll>(n, -1));
        cout<<func(0, n-1, dp, arr)+func(0, n-1, dp, arr)-sum<<endl;
    }
}