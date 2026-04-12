#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int INF = (int)1e9;

using ll = long long;

int main() {

    ll r, g, b;
    cin >> r >> g >> b;
    ll x = r * 100 + g * 10 + b;
    string ans = x % 4 == 0 ? "YES" : "NO";
    cout << ans;
    return 0;
}