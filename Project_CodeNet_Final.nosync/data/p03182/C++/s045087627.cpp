#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define int long long

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 2e5 + 5;

vector<ii> vec[N];

int dp[N], n, m, it[4 * N], lz[4 * N];

void lzupdate(int k, int l, int r) {
    if(!lz[k]) return ;
    it[k] += lz[k];
    if(l != r) {
        lz[k << 1] += lz[k];
        lz[k << 1 | 1] += lz[k];
    }
    lz[k] = 0;
}

int get(int k, int l, int r, int L, int R) {
    lzupdate(k, l, r);
    if(r < L || R < l || L > R) return 0;
    if(L <= l && r <= R)
        return it[k];
    int mid = (l + r) >> 1;
    return max(get(k << 1, l, mid, L, R), get(k << 1 | 1, mid + 1, r, L, R));
}

void update(int k, int l, int r, int L, int R, int val) {
    lzupdate(k, l, r);
    if(r < L || R < l || L > R) return ;
    if(L <= l && r <= R) {
        lz[k] += val;
        lzupdate(k, l, r);
        return ;
    }
    int mid = (l + r) >> 1;
    update(k << 1, l, mid, L, R, val);
    update(k << 1 | 1, mid + 1, r, L, R, val);
    it[k] = max(it[k << 1], it[k << 1 | 1]);
}

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        vec[r].pb({l, a});
    }
    for(int i = 1; i <= n; i++) {
        update(1, 0, n, i, i, get(1, 0, n, 0, i - 1));
        for(int j = 0; j < vec[i].size(); j++) {
            ii l = vec[i][j];
            update(1, 0, n, l.fi, i, l.se);
        }
    }
    cout << it[1];
}
