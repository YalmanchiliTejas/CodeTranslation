#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const int N = 3e3+5;

int n;
ll a[N];

ll dp[N][N],s;

ll solve(int from,int to){
    if(from>to)return dp[from][to]=0;
    if(from==to)return dp[from][to]=a[from];
    if(from+1==to)return dp[from][to]=max(a[from],a[to]);
    if(dp[from][to]!=-1)return dp[from][to];

    ll b=a[from]+min(solve(from+2,to),solve(from+1,to-1));
    ll c=a[to]+min(solve(from,to-2),solve(from+1,to-1));

    dp[from][to]=max(b,c);
    return dp[from][to];
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }

    memset(dp,-1,sizeof(dp));
    solve(1,n);

    cout<<2LL*dp[1][n]-s;
    return 0;
}

