#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define INF 10000000000
#define MOD 1000000007
using namespace std;
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int sa;
    if(x < y) {
        sa = y - x;
        if(a * x + b * y < x * 2 * c + sa * b) {
            cout << a * x + b * y;
        } else {
            cout << min(x * 2 * c + sa * b, y * 2 * c);
        }
    } else {
        sa = x - y;
        if(a * x + b * y < y * 2 * c + sa * a) {
            cout << a * x + b * y;
        } else {
            cout << min(y * 2 * c + sa * a, x * 2 * c);
        }
    }
    return 0;
}