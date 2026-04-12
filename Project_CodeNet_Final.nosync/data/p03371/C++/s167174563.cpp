#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = a * x + b * y;
    int ttl = x + y;
    int min_x = 0;
    int min_y = 0;

    for (int i = 0; i <= ttl; ++i) {
        int tmp = i * 2 * c + max(0, x - i) * a + max(0, y - i) * b;
        if (tmp <= ans) {
            ans = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}