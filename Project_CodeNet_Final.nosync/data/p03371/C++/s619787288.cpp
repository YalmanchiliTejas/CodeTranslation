#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int l, m, n, mini = min(x, y);
    l = a * x + b * y;
    m = (2 * c * mini) + ((x - mini) * a) + ((y - mini) * b);
    n = (2 * c * max(x, y));

    cout << min(min(l, m), n) << endl;

    return 0;
}