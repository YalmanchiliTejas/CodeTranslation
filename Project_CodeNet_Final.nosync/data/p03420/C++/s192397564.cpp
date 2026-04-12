#include <iostream>
#include <algorithm>

#define int long long int

main()
{
    int n, k;
    std::cin >> n >> k;

    int ans = 0;

    if (k == 0)
    {
        std::cout << n * n;
        return 0;
    }

    for (int i = k + 1; i <= n; ++i)
    {
        int pir = i - k;
        ans += (n / i) * pir;

   //     std::cout << ans << " ";

        int remainder = n % i;
        ans += std::max(0LL, remainder - k + 1);
 //       std::cout << ans << "\n";
    }

    std::cout << ans;
}
