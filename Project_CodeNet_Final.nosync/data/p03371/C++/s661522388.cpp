#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int f1 = a * x + b * y;
   
    // Bに合わせる
    int f2 = 0;
    f2 = c * 2 * y;
    f2 += a * max(0, (x - y));
    
    int f3 = 0;
    f3 = c * 2 * x;
    f3 += b * max(0, (y - x));

    int f4 = 0;
    f4 = c * 2 * max(x, y);

    cout << min(min(f1, f2), min(f3, f4)) << endl;

    return 0;
}