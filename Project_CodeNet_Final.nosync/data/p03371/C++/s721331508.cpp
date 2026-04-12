#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int a, b, c, x, y;

int main()
{
    cin >> a >> b >> c >> x >> y;
    int ans = 1 << 30;
    for (int i = 0; i <= 100000; i++)
    {
        int price = 2 * c * i + max(0, x - i) * a + max(0, y - i) * b;
        ans = min(ans, price);
    }
    cout << ans << endl;
}
