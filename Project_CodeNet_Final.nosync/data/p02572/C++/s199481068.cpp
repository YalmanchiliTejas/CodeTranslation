#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
ll a[200005];

int main(){
    ll sum = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        sum -= a[i];
        if(sum < 0)
            sum += MOD;
        ans = (ans + sum * a[i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
