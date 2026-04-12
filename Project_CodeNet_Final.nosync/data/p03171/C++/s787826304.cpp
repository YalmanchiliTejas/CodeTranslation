#include <bits/stdc++.h>
using namespace std;
const int mx = 3005;

int n, a[mx];
int vis[mx][mx][2];
long long dp[mx][mx][2];

long long fun(int i, int j, int t){
    if(i > j) return 0;

    long long &ans = dp[i][j][t];
    if(vis[i][j][t]) return ans;
    vis[i][j][t] = 1;

    ans = a[i] - fun(i+1, j, !t);
    ans = max(ans, a[j] - fun(i, j-1, !t));
    return ans;
}

int main(){

    cin.tie( nullptr );
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cout << fun(0, n-1, 0) << "\n";
    return 0;
}
