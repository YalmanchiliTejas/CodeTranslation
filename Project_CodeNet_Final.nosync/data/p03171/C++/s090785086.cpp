# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N = 3005;
ll dp[N][N], a[N], sum[N], n;
ll f(int l, int r){
    return sum[r] - sum[l - 1];
}
ll calc(int l, int r){
    if(l > r)return 0;
    if(dp[l][r] != 0)return dp[l][r];
    return dp[l][r] = f(l, r) - min(calc(l + 1, r), calc(l, r - 1));
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    cout << 2 * calc(1, n) - sum[n] << endl; 
}    