#include <bits/stdc++.h>
typedef long long ll;
#define fr first
#define sc second
#define int ll

using namespace std;
const int MN = 3e3+7;
const int MA = 5e6+7;

int a[MN], cnt[5];
int dp[MN][MN];

signed main(){
    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++)cin >> a[i];
    for(int z = 1; z <= n; z++){
        for(int l = 0; l < n-z+1; l++){
            int r = l+z-1;
            if(l == r){
                dp[l][r] = a[l];
                //cout << l << ' ' << r << " : " << dp[l][r] << endl;
                continue;
            }
            dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            //cout << l << ' ' << r << " : " << dp[l][r] << endl;
        }
    }
    cout << dp[0][n-1] << endl;
}
