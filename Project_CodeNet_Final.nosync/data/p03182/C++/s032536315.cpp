#include <bits/stdc++.h>
#define int long long
#define maxn 200005
using namespace std;

const int INF = 1e18;

struct Node {
    int dp, sum, mx;
    Node() {
        mx = dp = sum = 0;
    }
} tr[maxn * 4];

void pull(int x) {
    int L = x << 1;
    int R = L + 1;
    tr[x].sum = tr[L].sum + tr[R].sum;
    tr[x].dp = min(tr[L].dp, tr[R].dp);
    tr[x].mx = min(tr[L].mx + tr[R].sum, tr[R].mx);
}

void set_dp(int p, int v, int x = 1, int L = 0, int R = maxn) {
    if(L == R)  {
        tr[x].dp = min(tr[x].dp, v);
        tr[x].mx = min(tr[x].mx, v);
        return;
    }
    int m = (L + R) >> 1;
    if(p <= m) set_dp(p, v, x << 1, L, m);
    else set_dp(p, v, (x << 1) | 1, m + 1, R);
    pull(x);
}

void add(int p, int v, int x = 1, int L = 0, int R = maxn) {
    if(L == R)  {
        tr[x].sum += v;
        return;
    }
    int m = (L + R) >> 1;
    if(p <= m) add(p, v, x << 1, L, m);
    else add(p, v, (x << 1) | 1, m + 1, R);
    pull(x);
}

int ask() {
    return tr[1].mx;
}

map<int, int> T[maxn];
int n, m, sum = 0;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int l, r, a;
        cin >> l >> r >> a;
        T[r][l] += a; sum += a;
    }
    for(int i = 1; i <= n; i++) {
        T[i][i] += 0;
    }
    for(int i = 1; i <= n; i++) {
        set_dp(i, ask());
        for(auto it : T[i]) {
            add(it.first, it.second);
        }
    }
    cout << sum - ask() << '\n';
    return 0;
}

