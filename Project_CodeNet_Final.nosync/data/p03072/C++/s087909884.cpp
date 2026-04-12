#include <bits/stdc++.h>

#define REP(i, n) for(decltype(n) i = 0; i < n; i++)

#define ALL(c)   c.begin(), c.end()
#define SORT(c)  std::sort(ALL(c))
#define RSORT(c) std::sort(ALL(c), std::greater<decltype(c)::value_type>())

using namespace std;
using ll = long long;

const int MOD  = (int)1e9 + 7;
const int INF  = (int)1e9 + 1;
const ll  LINF = (ll)1e18 + 1;

int main() {
    try {
        cin.tie(0);
        ios::sync_with_stdio(false);

        int N;
        std::cin >> N;

        vector<int> H(N);
        REP(i, N) {
            std::cin >> H[i];
        }

        int ans = 0;
        REP(i, N) {
            bool ok = true;
            for(int j = 0; j < i; j++) {
                if(H[i] < H[j]) {
                    ok = false;
                    break;
                }
            }
            ans = (ok) ? ans + 1 : ans;
        }

        std::cout << ans << std::endl;
    }
    catch(const exception& e) {
        std::cout << e.what() << std::endl;
        exit(1);
    }
    return 0;
}
