#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = 100 * a + 10 * b + c;
    if (d % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
