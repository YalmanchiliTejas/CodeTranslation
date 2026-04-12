#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int a, b, c, x, y; std::cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(a+b > 2*c) {
        ans += std::min(x, y)*2*c;
        if(std::min(x, y) == x) {
            ans += (y-x)*b;
        } else {
            ans += (x-y)*a;
        }

        int ans1 = 0;
        ans1 += std::max(x, y)*c*2;

        ans = std::min(ans1, ans);
    } else {
        ans += a*x + b*y;
    }


    std::cout << ans << std::endl;
}