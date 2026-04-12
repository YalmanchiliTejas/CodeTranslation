#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll dp[3010][3010];
ll arr[3010];
ll n;

ll go(int i, int j){
    if(i > j)   return 0;
    if(dp[i][j] != -1)  return dp[i][j];
    return dp[i][j] = max(arr[i]-go(i+1,j),arr[j]-go(i,j-1));
}
int main(){
    memset(dp,-1,sizeof dp);
    ll k;
    scanf("%lld",&n);
    for(int i = 1; i <= n; i++){
        scanf("%lld",arr+i);
    }
    ll ans = go(1,n);
    printf("%lld\n",ans);
}
