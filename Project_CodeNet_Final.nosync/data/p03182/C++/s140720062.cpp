
#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 2e5;
const num inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
num w[nsz + 5], dp[nsz + 5], ans;
pair<pair<int, int>, int> dat[nsz + 5];
vector<int> sl[nsz + 5], sr[nsz + 5];

struct segment_tree {
#define ls (u << 1)
#define rs (u << 1 | 1)
    num mx[4 * nsz + 5], del[4 * nsz + 5];
    
    void inline down(int u) {
        if (!del[u])  return;
        mx[ls] += del[u];
        del[ls] += del[u];
        mx[rs] += del[u];
        del[rs] += del[u];
        del[u] = 0;
    }
    
    void inline upd(int el, int er, num val, int u = 1, int l = 0, int r = n) {
        if (l >= el && r <= er) {
            mx[u] += val;
            del[u] += val;
            return;
        }
        down(u);
        int md = (l + r) >> 1;
        if (el <= md) {
            upd(el, er, val, ls, l, md);
        }
        if (er > md) {
            upd(el, er, val, rs, md + 1, r);
        }
        mx[u] = max(mx[ls], mx[rs]);
    }
    
    num inline qry(int el, int er, int u = 1, int l = 0, int r = n) {
        if (l >= el && r <= er)  return mx[u];
        down(u);
        int md = (l + r) >> 1;
        num res = -inf;
        if (el <= md) {
            res = qry(el, er, ls, l, md);
        }
        if (er > md) {
            res = max(res, qry(el, er, rs, md + 1, r));
        }
        return res;
    }
};
segment_tree tr;

int main() {
    scanf("%d%d", &n, &m);
    cont (i, m) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        w[l] += c;
        w[r + 1] -= c;
        dat[i] = make_pair(make_pair(l, r), c);
        sl[l].push_back(i);
        sr[r].push_back(i);
    }
    cont (i, n) {
        w[i] += w[i - 1];
    }
    cont (i, n) {
        dp[i] = tr.qry(0, i - 1) + w[i];
        tr.upd(i, i, dp[i]);
        loop (j, sl[i].size()) {
            int id = sl[i][j], l = dat[id].first.first, r = dat[id].first.second, c = dat[id].second;
            tr.upd(l, r, -c);
        }
        loop (j, sr[i].size()) {
            int id = sr[i][j], l = dat[id].first.first, r = dat[id].first.second, c = dat[id].second;
            tr.upd(l, r, +c);
        }
    }
    cont (i, n) {
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);
}