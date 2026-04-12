#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define debug2(x,y) cout << x << " " << y << "\n"

ll const mod  = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<ll>arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    ll ans = 0, sum = 0;
    for(int i = 0; i < n ; i++){
        ans = (ans + (arr[i] * sum) % mod) % mod;
        sum = (sum + arr[i]) % mod;
    }
    cout << ans << "\n";
}




