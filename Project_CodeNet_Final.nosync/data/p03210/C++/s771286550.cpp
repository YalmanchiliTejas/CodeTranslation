#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cout << (#x) << " = " << (x) << "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, k, n) for (int i = (k); i < (int)(n); ++ i)
#define ALL(r) r.begin(), r.end()
#define DUP(x, y) (((x) + (y) - 1) / (y))
#define YES puts("YES")
#define NO puts("NO")
#define Yes puts("Yes")
#define No puts("No")

using ll = std::int64_t;
using vint = std::vector<int>;
using vll = std::vector<ll>;
using pint = std::pair<int, int>;

constexpr std::int32_t INF = 1001001001;

void Main() {
    int x;
    cin >> x;
    if (x == 7 || x == 5 || x == 3)YES;
    else NO;
}

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

