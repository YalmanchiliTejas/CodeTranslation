/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
signed main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());

    int ret = 0;
    while (a[0] >= n) {
        for (int i = 0; i < n; i++) {
            auto num = (int) ceil(1.0 * (a[i] - (n - 1)) / n);
            num = max(0LL, num);
            a[i] -= num * n;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                a[j] += num;
            }
            ret += num;
        }
        sort(a, a + n, greater<int>());
    }

    cout << ret << endl;

    return 0;
}