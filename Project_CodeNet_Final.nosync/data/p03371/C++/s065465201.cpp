#include <bits/stdc++.h>
using namespace std;
static const int MAX = pow(10, 5);

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int m = a * x + b * y;
    for(int i = 0; i <= MAX; i++) {
        m = min(m, max(x - i, 0) * a + max(y - i, 0) * b + i * 2 * c);
    }
    cout << m << endl;
}