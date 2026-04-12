//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("fma,avx,avx2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define x first
#define y second

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No");

    return 0;
}
