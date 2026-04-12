#include "bits/stdc++.h"

#ifndef DEBUG
#define dump(...)
#endif

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, ab, need_a, need_b;
    std::cin >> a >> b >> ab >> need_a >> need_b;

    int value1 = (2 * ab) * std::max(need_a, need_b);

    int value2 = a * need_a + b * need_b;

    int value3 = (2 * ab);
    if (need_a < need_b) {
        value3 *= need_a;
        need_b -= need_a;
        value3 += b * need_b;
    } else {
        value3 *= need_b;
        need_a -= need_b;
        value3 += a * need_a;
    }


    dump(value1, value2, value3);
    std::cout << std::min({value1, value2, value3}) << "\n";

    return 0;
}
