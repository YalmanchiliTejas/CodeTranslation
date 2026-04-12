#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double PI = 3.14159265358979323846;
const ll MOD = 1e9 + 7;
const ll TARGET = (1LL << 32) - 1LL;

template <typename T>
T Max(T val1, T val2) {
    return val1 > val2 ? val1 : val2;
}

template <typename T, typename... Args>
T Max(T val, Args... arg) {
    T result = Max(arg...);
    return Max(val, result);
}

template <typename T>
inline T read() {
    T X = 0, w = 0;
    char ch = 0;
    while (!isdigit(ch)) {
        w |= ch == '-';
        ch = getchar();
    }
    while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
    return w ? -X : X;
}

const int MAXN = 500005;
int n, m, k;
int w, h;
struct Entry {
    ll v;
    int id;
    Entry(ll v, int id) : v(v), id(id) {}
    bool operator<(const Entry& other) const { return v < other.v; }
};

ll arr[MAXN];
bool vis[MAXN];
int lf[MAXN], rt[MAXN];
int main() {
#ifdef LOCALLL
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &n);
    priority_queue<Entry> PQ;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &arr[i]);
        lf[i] = i - 1;
        rt[i] = i + 1;
        PQ.push(Entry(arr[i], i));
    }
    arr[0] = -INF64;
    arr[n + 1] = -INF64;
    rt[0] = 1;
    lf[n + 1] = n;
    ll ans = 0;
    for (int i = 0; i < n / 2; i++) {
        while (!PQ.empty() && vis[PQ.top().id]) {
            PQ.pop();
        }
        auto cur = PQ.top();
        PQ.pop();
        ans += cur.v;
        vis[lf[cur.id]] = vis[rt[cur.id]] = true;
        arr[cur.id] = arr[lf[cur.id]] + arr[rt[cur.id]] - cur.v;
        cur.v = arr[cur.id];
        lf[cur.id] = lf[lf[cur.id]];
        rt[lf[cur.id]] = cur.id;
        rt[cur.id] = rt[rt[cur.id]];
        lf[rt[cur.id]] = cur.id;
        PQ.push(cur);
    }
    printf("%lld", ans);
    return 0;
}