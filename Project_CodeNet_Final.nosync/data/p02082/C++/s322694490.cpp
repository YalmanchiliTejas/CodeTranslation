#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i, a, b) for(int i = (int)(a);i < (int)b; ++i)
#define ll long long

void solve() {
    int s, t, p, q, M, y;
    cin >> s >> t >> p >> q >> M >> y;
    cout << (t ^ y ^ s) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);



    solve();

    return 0;
}
