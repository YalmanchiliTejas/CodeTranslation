#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll m = 1e9 + 7;
string s;
ll n,d;
ll a[10005];
ll dp[10005][101][2];
ll solve(ll idx,ll sum,ll flag){
    if(idx > n){
        if(sum == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[idx][sum][flag] != -1){
        return dp[idx][sum][flag];
    }
    ll limit = 9;
    if(!flag){
        limit = a[idx];
    }
    ll ans = 0;
    for(int i=0;i<=limit;i++){
        if(i < limit || flag == 1){
            ans += solve(idx + 1,(sum + i) % d, 1);
            ans %= m;
        }
        else{
            ans += solve(idx + 1,(sum + i) % d, 0);
            ans %= m;
        }
    }
    return dp[idx][sum][flag] = ans%m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    cin>>d;
    n = s.length();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=d;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k] = -1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        a[i] = s[i-1] - '0';
    }
    ll ans = solve(1,0,0);
    cout<<(ans - 1 + m) % m <<"\n";
}