#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    for (int b = k + 1; b < n + 1; b ++){
        ll u = n / b;
        ll tmp = u * (b - k);
        if (n % b > 0) tmp += max(ll(0), ll(n % b - max(1, k) + 1));
        ans += tmp;
    }
    cout << ans << endl;
}