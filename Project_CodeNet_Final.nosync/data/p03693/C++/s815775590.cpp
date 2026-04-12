#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int MOD = 1000000007;
const long long INF = 1LL << 60;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    if ((10 * g + b) % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}