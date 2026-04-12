#include <bits/stdc++.h>

using namespace std;

long int MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<long int> a(n);

    long int all = 0;

    for(int i = 0; i < n; ++i){
        cin >> a[i];

        all += a[i];
        all %= MOD;
    }

    long int ans = 0;

    for(int i = 0; i < n; ++i){
        all -= a[i];

        if(all < 0) all += MOD;

        ans += (all * a[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}