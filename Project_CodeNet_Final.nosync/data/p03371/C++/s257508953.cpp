#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
#include <cmath>

typedef long long ll;

int main() {
    ll a,b,c,x,y;
    std::cin >> a >> b >> c >> x >> y;

    ll ooi_nedan = x > y ? a : b;
    ll ans1 = a * x + b * y;
    ll ans2 = c * 2 * std::max(x,y);
    ll ans3 = c * 2 * std::min(x,y) + ooi_nedan * std::abs(x-y);

    std::cout << std::min(ans1, std::min(ans2,ans3)) << std::endl;
    return 0;
}

