#include <bits/stdc++.h>

using std::ios_base;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::fixed;

using std::vector;
using std::string;
using std::stack;
using std::queue;
using std::deque;
using std::map;
using std::set;
using std::unordered_map;
using std::unordered_set;

using std::tuple;
using std::make_tuple;
using std::pair;
using std::make_pair;

using std::sort;
using std::reverse;
using std::nth_element;

#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int MAXN = 200005;
const int INF = 1e9;
const int MOD = 1e9+7;
const int64_t L_INF = 4e18;

int n;
pair<int, int> x[MAXN];
int b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x, x + n);

    for (int i = 0; i < n; i++) {
        int j = n / 2 - (i >= n / 2);
        b[x[i].second] = x[j].first;
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << '\n';

    #ifdef LOCAL
        cerr << "\n== " << 1.0 * clock() / CLOCKS_PER_SEC << " sec.\n";
    #endif
    return 0;
}