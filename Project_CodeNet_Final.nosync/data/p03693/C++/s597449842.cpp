#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int num = 100 * r + 10 * g + 1 * b;

    if (num % 4 == 0) {  // 4の倍数
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}