#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;
const int MAX = 3000;

ll a[MAX];
vector<vector<vector<ll>>> dp(MAX,vector<vector<ll>>(MAX,vector<ll>(2,-1)));

ll dfs(int i, int j, int c){
    if(dp[i][j][c] != -1) return dp[i][j][c];
    if(i == j) {
        if(c == 1) return dp[i][j][c] = a[i];
        else return dp[i][j][c] = -a[i];
    }
    if(c == 1) {
        ll d = max(a[i]+dfs(i+1,j,0),a[j]+dfs(i,j-1,0));
        return dp[i][j][c] = d;
    } else {
        ll d = min(-a[i]+dfs(i+1,j,1),-a[j]+dfs(i,j-1,1));
        return dp[i][j][c] = d;
    } 
}

int main(){
    int n;
    cin >> n;
    rep(i,n) cin >> a[i];
    cout << dfs(0,n-1,1) << endl;
    return 0;
}