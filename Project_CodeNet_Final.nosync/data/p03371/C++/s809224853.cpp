#include "bits/stdc++.h"

typedef long long ll;
using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    auto get_price = [&](int ab) {
        int p_ab = c * ab;
        int p_a = a * max(x - ab / 2, 0);
        int p_b = b * max(y - ab / 2, 0);
        return p_ab + p_a + p_b;
    };

    int ans = min({
       get_price(0),
       get_price(x * 2),
       get_price(y * 2),
    });

    cout << ans;

    return 0;
}
