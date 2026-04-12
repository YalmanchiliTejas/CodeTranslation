#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll a[n];
    ll s[n+1];
    s[0] = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s[i+1] = s[i] + a[i]; 
    }

    for(int i = 0; i < n-1; i++) {
        int j = i + 1;
        ll sum = s[n] - s[j];
        ans = (ans%M + (((a[i]%M) * (sum%M))%M))%M;
    }

    cout << ans;
}