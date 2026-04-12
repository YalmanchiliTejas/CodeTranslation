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
    rep(i, X) {
        if (X < i * Y + (i + 1) * Z) { // 超えたら、一つ前の値を答えとする
            ans = i - 1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
