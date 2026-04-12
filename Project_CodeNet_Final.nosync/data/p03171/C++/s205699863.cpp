#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[3001];
int main(){
    cin>>n;	for(ll i = 1; i <= n; i++)	cin>>a[i];
    ll dp[2][n+1];	memset(dp, 0, sizeof(dp));
    for(ll l = n; l > 0; l--){
        for(ll r = 1; r <= n; r++){
            if(l > r)   continue;
            bool taro = ((r-l+1)&1) == (n&1);
            ll op1 = a[l] * (taro?1:-1) + dp[(l+1)%2][r];
            ll op2 = a[r] * (taro?1:-1) + dp[l%2][r-1];
            dp[l%2][r] = taro ? max(op1, op2) : min(op1, op2);
        }
    }
    cout<<dp[1][n];
}

// Time: O(N*N)