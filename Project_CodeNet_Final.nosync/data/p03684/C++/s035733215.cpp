#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const int N = 2e6 + 10;

struct pt {
    ll x, y, n;
} a[N];

bool cmpx(pt a, pt b) {
    return a.x < b.x;
}

bool cmpy(pt a, pt b) {
    return a.y < b.y;
}


struct edge {
    ll v, u, w;
    bool operator < (const edge a) const {
        return w < a.w || w == a.w && v < a.v || w == a.w && v == a.v && u < a.u;
    }
};

edge g[N];
ll rnk[N], par[N];
set <edge> st;

void makeSet(int x) {
    rnk[x] = 0;
    par[x] = x;
}

int findSet(int x) {
    if (x == par[x])
        return x;
    return par[x] = findSet(par[x]);
}

void unionSets(int a, int b) {
    int a1 = findSet(a);
    int b1 = findSet(b);
    if (a1 == b1)
        return;
    if (rnk[a1] < rnk[b1])
        swap(a1, b1);
    if (rnk[a1] == rnk[b1])
        rnk[a1]++;
    par[b1] = a1;
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i].x >> a[i].y;
        a[i].n = i;
    }
    sort(a, a + n, cmpx);
    fr(i, n - 1) {
        g[i].v = a[i].n;
        g[i].u = a[i + 1].n;
        g[i].w = abs(a[i].x - a[i + 1].x);
        st.insert(g[i]);
    }

    sort(a, a + n, cmpy);
    fr(i, n - 1) {
        g[i + n - 1].v = a[i].n;
        g[i + n - 1].u = a[i + 1].n;
        g[i + n - 1].w = abs(a[i].y - a[i + 1].y);
        st.insert(g[i + n - 1]);
    }

    fr(i, n)
        makeSet(i);

    ll ans = 0, qua = 0;

    for (auto it = st.begin(); it != st.end(); it++) {
        edge t = *it;
        if (findSet(t.v) != findSet(t.u)) {
            unionSets(t.v, t.u);
            ans += t.w;
            qua++;
        }
        if (qua == n - 1)
            break;
    }
    cout << ans;

}
