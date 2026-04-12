#include <bits/stdc++.h>
#define int long long
#define INF 10000000000000000
using namespace std;
int n;
int a[200005];
bool vis[200005][2];
int dp[200005][2];
//0-> take either
//1->take the second one
int even(int i, int bound){
    if(i>=n) return 0;
    if(vis[i][bound]) return dp[i][bound];
    int tr = -INF;
    if(bound==0) tr = max(tr, a[i] + even(i+2, 0));
    tr = max(tr, a[i+1] + even(i+2, 1));
    vis[i][bound] = true;
    return dp[i][bound] = tr;
}
int odd(int i){
    if(i>=n) return 0;
    if(vis[i][0]) return dp[i][0];
    int tr = -INF;
    tr = max(tr, a[i] + odd(i+2));
    tr = max(tr, even(i+1, 0));
    vis[i][0] = true;
    return dp[i][0] = tr;
}
int32_t main() {
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++) vis[i][0] = vis[i][1] = false;
    if(n%2) cout<<odd(1)<<endl;
    else cout<<even(1, 0)<<endl;
    return 0;
}
//-2 4 5 5 6 8
//8 -2 6 4 5 5
//5 5 4 6 -2 8