#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, x, y;
    scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);

    ll ans = a * x + b * y;
    for (int i = 0; i <= max(x, y); i++) {
        ll price = a * max(0, (x - i)) + b * max(0, (y - i)) + c * 2 * i;
        ans = min(ans, price);
    }

    printf("%lld\n", ans);

    return 0;
}