#include <bits/stdc++.h>
#define ll long long
int main()
{
    ll n;
    std::vector<ll> a;
    std::cin >> n;
    const ll pack = 1000000007;
    for (int i = 0; i < n; ++i) {
        ll temp = 0;
        std::cin >> temp;
        a.push_back(temp);
    }
    ll ans = 0;
    ll temp_sum = 0;
    for (int i = 0; i < n; ++i) {
        temp_sum += a[i];
        temp_sum %= pack;
    }
    ans += (temp_sum % pack) * (temp_sum % pack);
    ans %= pack;
    for (int i = 0; i < n; ++i) {
        ans -= (a[i] % pack) * (a[i] % pack);
        ans %= pack;
    }
    while (ans < 0) {
        ans += pack;
    }
    if (ans % 2 != 0) {
        ans += pack;
    }
    ans /= 2;
    ans %= pack;
    std::cout << ans << std::endl;

    return 0;
}