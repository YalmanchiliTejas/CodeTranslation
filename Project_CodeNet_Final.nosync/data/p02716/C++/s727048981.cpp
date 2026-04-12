#include <bits/stdc++.h>
using namespace std;
#define int long long 
using ldb = long double;
using pa = pair < int, int >;
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
const int MOD = 1e9 + 7, N = 2e5 + 10;
const int LINF = LLONG_MAX;
int a[N];
int dp[N][4];
int vis[N][4];
int n;
int dfs(int pos,int skip){
    if(pos <= 0){
        return 0;
    }
    if(vis[pos][skip]){
        return dp[pos][skip];
    }
    vis[pos][skip] = 1;
    if(skip == 0){
        dp[pos][skip] = a[pos] + max({dfs(pos-2,0),dfs(pos-3,1),dfs(pos-4,2)});
    }
    else if(skip == 1){
        dp[pos][skip] = a[pos] + max(dfs(pos-2,1),dfs(pos-3,2));
    }
    else{
        dp[pos][skip] = a[pos] + dfs(pos-2,2);
    }
    return dp[pos][skip];
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    f(i,1,n+1){
        cin >> a[i];
    }
    if(n&1){
        cout << max({dfs(n,0),dfs(n-1,1),dfs(n-2,2)});
    }
    else
        cout << max(dfs(n,1),dfs(n-1,2));
    return 0;
}
 