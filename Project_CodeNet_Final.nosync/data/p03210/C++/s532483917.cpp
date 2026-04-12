#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define dump(x) cout << x << endl
typedef int64_t Int;

using namespace std;
using Graph = vector<vector<Int>>;

const double pi = M_PI;
const Int MOD = 1000000007;

int main() {
    int x;
    cin >> x;

    switch (x) {
    case 7:
    case 5:
    case 3:
        cout << "YES" << endl;
        break;

    default:
        cout << "NO" << endl;
        break;
    }

    return 0;
}
