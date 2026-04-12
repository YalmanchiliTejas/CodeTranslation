#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b <= 2 * c) { cout << a * x + b * y << '\n'; }
    else {
        int ans = 2 * c * min(x, y);
        if (x <= y) { ans += (y - x) * min(2 * c, b); }
        else { ans += (x - y) * min(2 * c, a); }
        cout << ans << '\n';
    }
}
