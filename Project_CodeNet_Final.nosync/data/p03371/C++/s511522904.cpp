#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int l, m, n;
    l = a * x + b * y;
    m = c * max(x, y) * 2;
    n = c * min(x, y) * 2 + a * (x - min(x, y)) + b * (y - min(x, y));
    cout << min(l, min(m, n)) << endl;

    return 0;
}