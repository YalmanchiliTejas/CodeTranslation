#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans = 0;
ll a[205000], s[205000];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        s[i] = a[i] + s[i-1];
    }
    for(int i=0; i<n; i++) {
        ans += a[i] * ((s[n-1] - s[i]) % 1000000007);
        ans %= 1000000007;
    }
    cout << ans  << endl;
}