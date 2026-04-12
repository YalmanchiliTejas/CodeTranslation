#include<bits/stdc++.h>
using namespace std;
#define N 3055
#define ll long long
int n,k;
ll dp[N][N], ar[N];

ll solve(int i, int j) {
    if(i>j)
        return 0;

    ll &ret = dp[i][j];
    if(~ret)
        return ret;

    ll c1 = ar[i] - solve(i+1,j);
    ll c2 = ar[j] - solve(i,j-1);
    return ret = max(c1,c2);
}

int main() {

    memset(dp, -1,sizeof dp);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%lld",&ar[i]);
    }
    cout << solve(1,n);

    return 0;
}
