#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cout << (#x) << " = " << (x) << "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define ALL(r) r.begin(), r.end()

using ll = std::int64_t;
using vint = std::vector<int>;
using pint = std::pair<int, int>;

constexpr std::int32_t INF = 1001001001;

void Main() {
    int n;
    cin >> n;
    vint h(n);
    for (auto& x : h)
    {
        cin >> x;
    }

    int ans = 0;
    int max_h = 0;
    rep(i, n) {
        if (max_h <= h[i]) {
            ++ans;
            max_h = h[i];
        }
    }

    cout << ans << endl;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
