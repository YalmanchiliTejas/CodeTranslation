#include <bits/stdc++.h>
using namespace std;

int n,S;
int a[3123];
long long dp[3123][3123];
long long MOD = 998244353;

int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);

    cin>>n>>S;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int s=0;s<=S;s++){
            dp[i][s] = dp[i-1][s];
            if(s-a[i]>0){
                dp[i][s] += dp[i-1][s-a[i]];
                dp[i][s]%=MOD;
            }
        }
        dp[i][a[i]]+=i;
        dp[i][a[i]]%=MOD;
    }
    long long res = 0;
    for(int i=1;i<=n;i++){
        res = (res+dp[i][S])%MOD;
    }
    cout << res;
}
