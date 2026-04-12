#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int mod = 1e9 + 7 ;
#define int long long int

int32_t main() {
    IOS ;
    // int t ; cin >> t ; while(t--) {}
    int n ; cin >> n ; int arr[n+1], dp[n+1] ;
    dp[0] = 0 ;
    for(int i=1; i<=n ; i++) {
        cin >> arr[i] ; 
        dp[i] = (dp[i-1] + arr[i]) % mod ;
    }
    
    int res = 0 ;
    for(int i=2; i<=n; i++) {
        int  x = (arr[i] * dp[i-1]) % mod ; 
        res = (res + x) % mod ;
    }
    
    cout << res ;
    
    return 0 ;
}
