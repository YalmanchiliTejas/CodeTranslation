#include <iostream>
using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    // 場合分け
    /*int m = min(x, y);
    x -= m, y -= m;

    int ans = min(2 * m * c, m * (a + b));

    ans += min(x * a, 2 * c * x) + min(y * b, 2 * c * y);

    cout << ans << '\n';
    */

    // 全探索
    // 1. ２個セットを何個購入するかを探索
    // 2. 足りない分をA,Bで補う
    int ans = a * x + b * y;
    for(int i = 1; i <= 100000; i++) {
       ans = min(ans, i*2*c + a*max(0, x - i) + b*max(0, y - i)); 
    }

    cout << ans << endl;

    return 0;
}