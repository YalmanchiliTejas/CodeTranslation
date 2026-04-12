#include <iostream>
#include <algorithm>
#include <numeric>


int64_t a[51];
int64_t p[51];

int64_t calc(int lv, int64_t x) {
    if(x == 0) return 0;
    if(lv == 0) return 1;
    if(x > a[lv] / 2) return p[lv-1] + calc(lv-1, x - a[lv] / 2 - 1) + 1;
    return calc(lv-1, x - 1);
}


int main(void) {
    int lv;
    int64_t x;
    std::cin >> lv >> x;

    a[0] = 1;
    p[0] = 1;
    for(int i=1; i<=lv; i++){
        a[i] = a[i-1] * 2 + 3;
        p[i] = p[i-1] * 2 + 1;
    }

    std::cout << calc(lv, x) << std::endl;

    return 0;
}
