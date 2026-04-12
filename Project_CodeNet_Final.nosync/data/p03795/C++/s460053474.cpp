#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, FN) for(int i = 0; i < (FN); i++)

int main() {
    int n, x, y;
    cin >> n;
    x = 800 * n;
    y = 200 * (int)(n / 15);
    cout << x - y << endl;

    return 0;
}
