#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n;
    cin >> n;
    vector<int> a(n);
    int mod = 1e9+7;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> asum(n, 0);
    asum[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--){
        asum[i] = (asum[i+1] + a[i]) % mod;
    }

    int ans = 0;
    for(int i=0; i<n-1; i++){
        ans = (ans + asum[i+1]*a[i]) % mod;
    }
    cout << ans << endl;

    

    return 0;
}