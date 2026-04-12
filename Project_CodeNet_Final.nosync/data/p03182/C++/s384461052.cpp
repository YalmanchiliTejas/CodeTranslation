#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m;
vector<ii> intervals[N];

struct It {
    long long node[N << 2], lz[N << 2];
    It () {
        memset(node, 0, sizeof node);
        memset(lz, 0, sizeof lz);
    }
    void trueVal (int nd, int Left, int Right) {
        if (!lz[nd]) return ;
        node[nd] += lz[nd];
        if (Left != Right) {
            lz[nd << 1] += lz[nd];
            lz[nd << 1 | 1] += lz[nd];
        }
        lz[nd] = 0;
    }
    void update (int nd, int Left, int Right, int l, int r, long long val) {
        trueVal(nd, Left, Right);
        if (Right < l || r < Left) return ;
        if (l <= Left && Right <= r) {
            lz[nd] = val; trueVal(nd, Left, Right);
            return ;
        }
        int mid = Left + Right >> 1;
        update(nd << 1, Left, mid, l, r, val); update(nd << 1 | 1, mid + 1, Right, l, r, val);
        node[nd] = max(node[nd << 1], node[nd << 1 | 1]);
    }
    long long get (int nd, int Left, int Right, int l, int r) {
        trueVal(nd, Left, Right);
        if (Right < l || r < Left) return 0;
        if (l <= Left && Right <= r) return node[nd];
        int mid = Left + Right >> 1;
        return max(get(nd << 1, Left, mid, l, r), get(nd << 1 | 1, mid + 1, Right, l, r) );
    }
} it;

int main () {
    scanf("%d %d", &n, &m);
    while (m --) {
        int l, r, a; scanf("%d %d %d", &l, &r, &a);
        intervals[r].pb(ii(l, a) );
    }

    it.update(1, 0, n, 0, 0, 0);
    for (int i = 1; i <= n; ++i) {
        it.update(1, 0, n, i, i, it.get(1, 0, n, 0, i - 1) );
        for (auto _ : intervals[i]) {
            it.update(1, 0, n, _.fi, i, _.se);
        }
    }

    printf("%lld", it.node[1]);

    return 0;
}
