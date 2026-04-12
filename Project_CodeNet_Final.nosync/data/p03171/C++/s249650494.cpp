#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mpr make_pair
#define mt make_tuple
 
using namespace std;
 
const ll N = 3010;
const ll mod = 1e9 + 7;
ll power(ll x, ll   y, ll p){ ll res = 1; x = x % p;while (y > 0){ if (y & 1) res = (res*x) % p; y = y>>1; x = (x*x) % p;} return res; }
ll n, sum;
ll arr[N], dp[N][N][2];

ll solve(int l, int r, int flag){
    if(l > r)   return 0;
    if(dp[l][r][flag] != -1)  return dp[l][r][flag];
    if(flag)    dp[l][r][flag] = min(solve(l+1,r,0) - arr[l], solve(l,r-1,0) - arr[r]);
    else    dp[l][r][flag] = max(arr[l] + solve(l+1,r,1), arr[r] + solve(l,r-1,1));
    return dp[l][r][flag];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sum = 0;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum += arr[i];
    }
    cout<<solve(0,n-1,0)<<endl;
    return 0;
}