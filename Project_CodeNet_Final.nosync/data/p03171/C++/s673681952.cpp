#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;

const int mx = 3005;

ll dp[mx][mx][2];
int n, a[mx];

ll fun(int i, int j, int t){
    if(i > j) return 0;
    ll &ans = dp[i][j][t];
    if(~ans) return ans; ans=0;

    ans = a[i] - fun(i+1, j, !t);
    ans = max(ans, a[j] - fun(i, j-1, !t));
    return ans;
}

void solve(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << fun(0, n-1, 0) << "\n";
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(0);

    int tc = 1;
    while(tc--) solve();
    return 0;
}

