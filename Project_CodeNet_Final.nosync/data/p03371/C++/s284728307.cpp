#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int n = a*x + b*y;
    int m = c*2*max(x,y);
    int l;
    if (x < y) l = c*2*x + b*(y-x);
    else       l = c*2*y + a*(x-y);

    cout << min({n, m, l}) << endl;
}