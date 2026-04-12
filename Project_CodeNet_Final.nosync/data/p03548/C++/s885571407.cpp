#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int ans;
    ans = (X - Z) / (Y + Z);

    cout << ans << endl;

    return 0;
}
