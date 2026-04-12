#include <bits/stdc++.h>
#define eps 1e-3
#define pi acos(-1.0)
#define inf 0x3f
#define INF 0x3f3f3f3f
#define pb push_back
#define debug1 cout<<"&&";
#define debug2 cout<<"**";
#define ms(a, x) memset(a, x, sizeof(a))
#define for0(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
using namespace std;
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef pair<long long, long long> pll;
const int mod = 1e9 + 7;
const int N = 2e5+10;
const int M = 1e6+10;
/*=================================================================================*/

ll s[N << 2], t[N << 2];
vector<pair<int, int> > a[N];
void add(int x, int L, int R, int l, int r, ll c) {
    if (l <= L && R <= r) return (void)(s[x] += c, t[x] += c);
    int mid = (L + R) >> 1;
    if (l <= mid) add(x << 1, L, mid, l, r, c);
    if (r > mid) add(x << 1 | 1, mid + 1, R, l, r, c);
    s[x] = max(s[x << 1], s[x << 1 | 1]) + t[x];
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        a[y].emplace_back(x, z);
    }
    for (int i = 1; i <= n; i++) {
        add(1, 1, n, i, i, s[1]);
        for (auto &it : a[i]) add(1, 1, n, it.first, i, it.second);
    }
    printf("%lld\n", max(s[1], 0ll));
    return 0;
}