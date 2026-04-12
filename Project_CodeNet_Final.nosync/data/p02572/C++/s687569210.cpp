#include <iostream>
#include <vector>

constexpr int mod = 1'000'000'007; // '

int main(void){
    std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
    int n; std::cin >> n;
    long long int res = 0, sum = 0;
    for(int i = 0; i < n; ++i){
        int a; std::cin >> a;
        res += sum * a; res %= mod;
        sum += a; if(sum >= mod) sum -= mod;
    }
    std::cout << res << '\n';
    return 0;
}