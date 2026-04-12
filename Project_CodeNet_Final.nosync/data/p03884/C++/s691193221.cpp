#include <bits/stdc++.h>
using ll = long long;
#define show(x) std::cerr << #x << " = " << (x) << std::endl
int main()
{
    ll K;
    std::cin >> K;
    const ll NUM = 700;
    std::vector<ll> num(NUM + 1);
    for (ll i = 0; i <= NUM; i++) { num[i] = i * (i + 1) / 2 * (i + 2) / 3 * (i + 3) / 4 * (i + 4) / 5 * (i + 5) / 6 * (i + 6) / 7; }
    bool usef = false;
    std::string ans;
    for (int i = NUM; i >= 1; i--) {
        const ll f = K / num[i];
        K %= num[i];
        if (f == 0 and not usef) { continue; }
        usef = true, ans += std::string(f, 'F') + "ESTIVAL";
    }
    assert(ans.size() <= 5000);
    std::cout << ans << std::endl;
    return 0;
}
