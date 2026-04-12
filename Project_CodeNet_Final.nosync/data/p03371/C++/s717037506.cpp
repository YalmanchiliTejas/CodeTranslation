#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans = 5000 * 1e5 * 20;
    for(int c_ab = 0; c_ab <= 2 * max(x, y); c_ab+=2) {
        long long cost = c_ab * c + max(0, (x - c_ab / 2)) * a + max(0, (y - c_ab / 2)) * b;
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}
