#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 4e5 + 3;
const ll ninf = std::numeric_limits<ll>::min();
int n, a[maxn];
std::map<int, ll> s[maxn];

void filter(int i) {
    static std::map<int, ll> t;
    t.clear();
    int r = (i + 1) / 2 + 5, l = r - 20;
    for(auto &&[u, v] : s[i]) {
        if(u < l || u > r)
            continue;
        t.emplace(u, v);
    }
    t.swap(s[i]);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    s[0][0] = 0;
    s[1][0] = 0;
    s[1][1] = a[0];
    s[2][0] = 0;
    s[2][1] = a[1];
    for(int i = 3; i <= n; ++i) {
        auto &cs = s[i];
        for(int j = std::max(i - 4, 0); j <= i - 2; ++j) {
            for(auto &&[x, y] : s[j]) {
                if(cs.find(x + 1) == cs.end())
                    cs[x + 1] = y + a[i - 1];
                else
                    cs[x + 1] = std::max(cs[x + 1], y + a[i - 1]);
            }
        }
        filter(i);
    }
    ll ans = ninf;
    for(int i = 0; i <= n; ++i) {
        if(s[i].find(n / 2) != s[i].end()) {
            ans = std::max(ans, s[i][n / 2]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}