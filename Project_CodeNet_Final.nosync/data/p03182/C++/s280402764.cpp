#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;
const llint INF = 1000000000000000000LL;

llint n, m, ofs = 1, sol;
llint dp[MAXN];
vector < pair <llint, llint> > lef[MAXN], rig[MAXN];

struct cvor {
    llint mx, prop;
} t[4*MAXN];

void propagate (int x) {
    if (t[x].prop == 0) return;
    t[x].mx += t[x].prop;
    if (x < ofs) {
        t[2*x].prop += t[x].prop;
        t[2*x+1].prop += t[x].prop;
    }
    t[x].prop = 0;
}

void update (int x, int from, int to, int low, int high, llint val) {
    propagate(x);
    if (to < low || high < from) return;
    if (from <= low && high <= to) {
        t[x].prop += val;
        propagate(x);
        return;
    }
    update(2*x, from, to, low, (low+high)/2, val);
    update(2*x+1, from, to, (low+high)/2+1, high, val);
    t[x].mx = max(t[2*x].mx, t[2*x+1].mx);
}

llint upit (int x, int from, int to, int low, int high) {
    propagate(x);
    if (to < low || high < from) return -INF;
    if (from <= low && high <= to) return t[x].mx;
    return max(upit(2*x, from, to, low, (low+high)/2), upit(2*x+1, from, to, (low+high)/2+1, high));
}

void sweep () {
    llint curr = 0;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<lef[i].size(); j++) {
            llint rr = lef[i] [j].first, cost = lef[i] [j].second;
            update(1, i, rr, 0, ofs-1, -cost);
            curr += cost;
        }
        for (int j=0; j<rig[i].size(); j++) {
            llint ll = rig[i] [j].first, cost = rig[i] [j].second;
            update(1, ll, i-1, 0, ofs-1, cost);
            curr -= cost;
        }
        dp[i] = upit(1, 0, i-1, 0, ofs-1) + curr;
        update(1, i, i, 0, ofs-1, dp[i]);
        sol = max(sol, dp[i]);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while (ofs < n+2) ofs *= 2;
    for (int i=0; i<m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        lef[l].push_back(make_pair(r, c));
        rig[r+1].push_back(make_pair(l, c));
    }
    sweep();
    cout << sol;
    return 0;
}
