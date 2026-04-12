#include <iostream>
#include <algorithm>
#include <cmath>

int main(void){
    int A, B, C, X, Y, min_p, d, ans=0;
    std::cin >> A >> B >> C >> X >> Y;

    min_p = std::min(X, Y);
    d = X - Y;

    if (A + B > 2 * C){
        ans += C * min_p * 2;
    } else {
        ans += (A + B) * min_p;
    }

    if (d > 0){
        if (A > 2 * C){
            ans += 2 * C * d;
        } else {
            ans += A * d;
        }
    } else if (d < 0){
        if (B > 2 * C){
            ans += 2 * C * -d;
        } else {
            ans += B * -d;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
