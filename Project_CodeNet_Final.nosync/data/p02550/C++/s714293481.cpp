#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>
#include <bitset>
#include <functional>
#include <iomanip>
#include <random>

#define FOR_LT(i, beg, end) for (decltype(beg) i = beg; i < end; i++)
#define FOR_LE(i, beg, end) for (decltype(beg) i = beg; i <= end; i++)
#define FOR_DW(i, beg, end) for (decltype(beg) i = beg; end <= i; i--)
#define REP(n)              for (decltype(n) repeat_index = 0; repeat_index < n; repeat_index++)

using namespace std;

struct N {
    int64_t c;
    uint64_t sum;
};

int64_t solve()
{

    uint64_t n, x, m;
    cin >> n >> x >> m;

    vector<N> ns(m + 100, { -1, 0 });
    uint64_t sum = 0;
    int64_t c = 0;
    bool has_loop = false;

    REP(n) {
        if (ns[x].c != -1) {
            has_loop = true;
            break;
        }
        ns[x].c = c;
        ns[x].sum = sum;

        c++;
        sum += x;
        x = x * x % m;
    }
    if (!has_loop) {
        return sum;
    }

    uint64_t ans = sum;
    uint64_t r = n - c;
    uint64_t rr = (c - ns[x].c);
    //cout << ans << " " << r << endl;
    //cout << (sum - ns[x].sum) << " " << (r / (c - ns[x].c)) << endl;
    ans += (sum - ns[x].sum) * (r / rr);
    r %= rr;
    REP(r) {
        ans += x;
        x = (x * x);
        x %= m;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(20);
    cout << solve() << endl;
    return 0;
}

