#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3+10;
ll n, v[maxn], dp[maxn][maxn];
ll solve(int l, int r){
    if(l > r or r < l) return 0;
    if(l == r) return dp[l][r] = v[l];
    if(dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max((v[l] - solve(l+1, r)), (v[r] - solve(l, r-1)));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> v[i];
    memset(dp, -1, sizeof dp);
    cout << solve(1, n) << "\n";
    return 0;
}