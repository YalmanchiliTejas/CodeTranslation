#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    X -= Z;
    int count = 0;
    while (X >= Y + Z) {
        count++;
        X -= (Y + Z);
    }

    cout << count << endl;

    return 0;
}
