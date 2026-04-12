#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define PI acos(-1.0)
#define mod 1e9+7
using namespace std;
ll dp[3001][3001];
ll arr[3001];
ll DP(int st, int end)
{
    if(st>end) return 0;
    if(st==end) return arr[st];
    if(dp[st][end]) return dp[st][end];
    return dp[st][end]=max(arr[st]-DP(st+1, end),arr[end]-DP(st,end-1));
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
        scanf("%lld", &arr[i]);
    ll ans=DP(0, n-1);
    printf("%lld\n", ans);
    return 0;
}
