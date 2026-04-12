#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define REP(i, n) for(long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    vector<int> check(m,-1);
    vector<int> a;
    int t = 0;
    ll total = 0;
    while (check[x] == -1) {
        a.push_back(x);
        check[x] = t;
        t++;
        total += x;
        x = (x * x) % m;
    }
    int c = t - check[x];
    ll s = 0;
    for (int i = check[x]; i < t; ++i){
        s += a[i];
    }
    ll ans = 0;
    if (n <= t) {
        rep(i, n){
            ans += a[i];
        }
    }
    else {
        ans += total;
        n -= t;
        ans += s * (n / c);
        n %= c;
        rep(i, n){
            ans += a[check[x] + i];
        }
    }
    cout << ans << endl;
    return 0;
}
