#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

int X, Y, Z;

int main() {
    cin >> X >> Y >> Z;

    // 1人目
    int ans = 1;
    X -= Y + 2 * Z;

    int add = X / (Y + Z);

    cout << ans + add << endl;
}