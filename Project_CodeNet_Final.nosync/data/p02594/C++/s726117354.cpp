#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define pi pair<int, int>
#define l first
#define r second
#define all(x) x.begin(), x.end()
#define fori(a, b, step) for (int i = a; i < b; i += step)
#define forj(a, b, step) for (int j = a; j < b; j += step)
#define int long long

const int maxn = 1e6 + 1, mod = 1e9 + 7;

using namespace std;

int a[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x; cin >> x;
    cout << (x >= 30 ? "Yes" : "No");
    return 0;
}
