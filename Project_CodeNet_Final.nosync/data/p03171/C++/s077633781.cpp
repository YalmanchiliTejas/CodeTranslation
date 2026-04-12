#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 3e3 + 50;
const ll mod = 1e9+7;
ll dp[maxn][maxn];
int n;
ll a[maxn];
ll dfs(int l, int r){
    if(dp[l][r]) return dp[l][r];
    if(l == r) return dp[l][r] = a[l];
    ll t1, t2;
    t1 = a[l] - dfs(l+1, r);
    t2 = a[r] - dfs(l, r-1);
    dp[l][r] = max(t1, t2);
    return dp[l][r];
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    printf("%lld\n", dfs(1,n));    
    return 0;
}



