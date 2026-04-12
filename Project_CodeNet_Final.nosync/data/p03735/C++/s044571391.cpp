#include <cstdio>
#include <algorithm>
#include <cmath>
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
using namespace std;
typedef long long ll;
const int MAXN = 200005;
const int INF = 1e9 + 1;
int n;
int r_min, r_max, b_min, b_max;
ll ans = (ll)1e18;

pair<int, int> s[MAXN];

int main() {
    scanf("%d", &n);
    r_min = INF, r_max = 0;
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d %d", &x, &y);
        s[i] = x < y ? make_pair(x, y) : make_pair(y, x);
        r_max = max(r_max, s[i].second), r_min = min(r_min, s[i].second);
    }
    sort(s + 1, s + n + 1);
    b_min = s[1].first, b_max = s[n].first;
    ans = min(ans, 1ll * (b_max - b_min) * (r_max - r_min));
    r_min = s[1].first, b_max = max(b_max, s[1].second);
    int _min = s[1].second;
    for (int i = 2; i < n; i++) {
        if ((b_min = s[i].first) > _min)
            break;
        ans = min(ans, 1ll * (b_max - b_min) * (r_max - r_min));
        b_max = max(b_max, s[i].second);
        _min = min(_min, s[i].second);
    }
    b_min = _min, ans = min(ans, 1ll * (b_max - b_min) * (r_max - r_min));
    printf("%lld", ans);
    return 0;
}
