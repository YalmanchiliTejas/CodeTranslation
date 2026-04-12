#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
int n;
ll a[200005],sum;
ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = (ans+a[i]*sum)%mod;
        sum += a[i];
        sum %= mod;
    }
    cout << ans;
}