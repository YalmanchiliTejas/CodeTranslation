#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int niz[3005];
ll dp[3005][3005];
 
int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;
 
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> niz[i];
        dp[i][i] = niz[i];
        if(n%2 == 0) dp[i][i] = -dp[i][i];
    }
    for(int len=2; len<=n; len++){
        for(int l=1; l+len-1<=n; l++){
            int r = l+len-1;
            if((n-len)%2 == 0){
                dp[l][r] = max(niz[l] + dp[l+1][r], niz[r] + dp[l][r-1]);
            }
            else{
                dp[l][r] = min(-niz[l] + dp[l+1][r], -niz[r] + dp[l][r-1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}