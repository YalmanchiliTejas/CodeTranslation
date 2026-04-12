#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

const long long int MOD = 1000000007;

int main(){
    int n;
    std::cin >> n;

    std::vector<long long int> a(n);
    long long int sum = 0;
        for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }
    
    long long int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum -= a[i];
        if (sum < 0)
        {
            sum += MOD;
        }
        ans += (a[i] * sum) % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }
    
    std::cout << ans << std::endl;

    return 0;
}