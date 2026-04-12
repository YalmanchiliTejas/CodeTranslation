#include <bits/stdc++.h>

#define FLASH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define MAX 1e9
#define MIN -1e9
#define mod 1000000007
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define output(x) cout << ( x ? "YES" : "NO" ) << '\n' ;
#define mxn 100005
using namespace std;

void solve(){
    int n;
    cin >> n ;
    int a[n + 1],pref[n + 2] = {};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i >= 1; i--){
        pref[i] = pref[i + 1] + a[i];
        pref[i] %= mod;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += a[i] * pref[i + 1];
        ans %= mod;
    }
    cout << ans ;
}

int32_t main()
{
    FLASH
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

