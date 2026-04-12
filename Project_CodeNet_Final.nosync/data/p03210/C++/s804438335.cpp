/**
*    created: 20.06.2020 13:33:22
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a;
    cin >> a;
    if (a == 3 || a == 5 || a == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}