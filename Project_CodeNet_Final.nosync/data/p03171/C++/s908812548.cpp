#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int , int>
#define fast ios_base::sync_with_stdio(0)
#define mx 3002
ll arr[mx], dp[mx][mx];
int n;
ll fun(int b, int e)
{
    if(b>e) return 0;
    if(b==e)
        return arr[b];
    ll& ret = dp[b][e];
    if(ret!=-1) return ret;
    ret = max(arr[b]  - fun(b+1,e) , arr[e] - fun(b, e-1));
    return ret;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%lld",&arr[i]);
    memset(dp, -1, sizeof dp);
    printf("%lld\n",fun(1,n));
}

