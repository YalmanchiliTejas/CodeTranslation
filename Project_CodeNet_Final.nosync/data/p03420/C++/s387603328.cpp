#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    int64_t n, k;
    std::cin >> n >> k;
    int64_t sum = 0;
    if(k ==0){
        std::cout << n *n << '\n';
        return 0;
    }
    for (int b = k+1; b <= n; ++b) {
        long long d = n-k;
        d /= b;
        long long l = k, r = b;
        while(l+1<r){
            long long m = (l+r)/2;
            if(m+d*b <= n){
                l = m;
            }
            else
                r = m;
        }
        long long x = l-k+1;
        long long y = b- l - 1;
        d++;
        sum += x * d + y * (d-1);
//        std::cerr << b << ':' << x << ',' << y << "::"<< d << ',' << sum << std::endl;
    }
    std::cout << sum << std::endl;
}