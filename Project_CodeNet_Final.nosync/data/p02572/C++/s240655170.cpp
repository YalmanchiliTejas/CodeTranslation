#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i) // マクロ
using namespace std;                          // stdの省略
using pii = pair<int, int>;                   // pairの略記
using ll = long long;                         // long longの略記
using ull = unsigned long long;                         // long longの略記

int main(void)
{

    int n;
    cin >> n;

    vector<int> a(n);
    ll sum = 0;
    ll mod = pow(10, 9) + 7;
    rep(i, n) {
        cin >> a.at(i);
        sum += a.at(i);
        sum %= mod;
    }

    ll ans = 0;
    rep(i,n) {
        sum -= a.at(i);
        if (sum < 0) sum += mod;
        ans += a.at(i) * sum;
        ans %= mod;
    }
    
    cout << ans << endl;

    return 0;
}