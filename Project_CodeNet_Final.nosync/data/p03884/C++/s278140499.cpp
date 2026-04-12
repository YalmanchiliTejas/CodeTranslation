#include <bits/stdc++.h>
using ll = long long;
int main()
{
    ll K;
    std::cin >> K;
    std::vector<ll> num(1000 + 1);
    for (ll i = 0; i <= 1000; i++) { num[i] = i * (i + 1) / 2 * (i + 2) / 3 * (i + 3) / 4 * (i + 4) / 5 * (i + 5) / 6 * (i + 6) / 7; }
    auto ok = [&](const int NUM) {  // 何もわからない...
        ll K = 1000000000000000000LL;
        bool usef = false;
        ll L = 0;
        for (int i = NUM; i >= 1; i--) {
            const ll f = K / num[i];
            K %= num[i];
            if (f == 0 and not usef) { continue; }
            usef = true, L += f + 7;
        }
        return L <= 5000;
    };
    int NUM = 1;
    for (; NUM <= 1000; NUM++) {
        if (ok(NUM)) { break; }
    }
    bool usef = false;
    std::string ans;
    for (ll i = NUM; i >= 1; i--) {
        const ll f = K / num[i];
        K %= num[i];
        if (f == 0 and not usef) { continue; }
        usef = true, ans += std::string(f, 'F') + "ESTIVAL";
    }
    assert(ans.size() <= 5000);
    std::cout << ans << std::endl;
    return 0;
}
