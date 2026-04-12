#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int ans = r * 100 + g * 10 + b;

    if (ans % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
