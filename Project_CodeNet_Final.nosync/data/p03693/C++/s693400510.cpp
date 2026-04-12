#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int r, g, b;
    cin >> r >> g >> b;
    if ((r * 100 + g * 10 + b) % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
