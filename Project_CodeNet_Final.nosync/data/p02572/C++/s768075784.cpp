#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;

    ll sum = 0;
    ll ans = 0;
    ll mod = 1e9 + 7;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        sum %= mod;
    }


    for(int i = 0; i < n ; i++){
        sum -= a[i];
        if(sum < 0)sum += mod;
        ans += a[i] * sum;
        if(ans < 0)sum += mod;
        ans %= mod;
    }
    cout << ans <<'\n';





}
