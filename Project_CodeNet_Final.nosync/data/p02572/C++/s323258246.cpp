#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1000000007;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<ll> s(n+1,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll sum = (s[n] - s[i + 1])%mod;
        ans += a[i]*sum;
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}