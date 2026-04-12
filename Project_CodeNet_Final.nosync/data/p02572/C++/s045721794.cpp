#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;
    ll a[n + 1], s[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0;
    for(int i = 1; i < n; i++){
        ll c = s[n] - s[i];
        c %= 1000000007;
        c *= a[i];
        c %= 1000000007;
        ans += c;
        ans %= 1000000007;
    }

    cout << ans << endl;


    return 0;
}
