#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int num;
    std::cin >> num;
    long A[num];
    std::vector<long long> B(num + 1, 0);
    for (int i = 0; i < num; i++)
    {
        std::cin >> A[i];
        B[i + 1] = B[i] + A[i];
    }

    int mod = 1000000007;
    long ans = 0;
    for (int i = 0; i < num; i++)
    {
        long long sum = (B[num] - B[i + 1]) % mod;
        //std::cout << sum_all << std::endl;
        ans += sum * A[i];
        ans %= mod;
    }

    //std::cout << (long)141421356*17320508 << std::endl;
    std::cout << ans << std::endl;
    return 0;
}