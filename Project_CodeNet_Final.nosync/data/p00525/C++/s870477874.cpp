#include <bits/stdc++.h>
using namespace std;

struct Line {
    int x1, y1, x2, y2;
    Line (int x1, int y1, int x2, int y2) :
        x1(x1), y1(y1), x2(x2), y2(y2) {}
};

struct Query {
    int l, r, id;

    Query (int l, int r, int id) :
        l(l), r(r), id(id) {}

    void dbg() {
        cout << "Query " << l << ' ' << r << ' ' << id << '\n';
    }
};

struct Update {
    int p, t, id;

    Update (int p, int t, int id) :
        p(p), t(t), id(id) {}

    void dbg() {
        cout << "Update " << p << ' ' << t << ' ' << id << '\n';
    }
};

const int N = 100010;

int w, h, n, cnt;
int it[2][8 * N];
int go[2][40 * N];
int pos[40 * N];
bool visit[40 * N];
long long cntv, cnte, cntc;
vector<Line> a;
vector<int> vx, vy, G[N];
vector<Update> update[N * 2];
vector<Query> query[N * 2];

void addEdge(int u, int v) {
//    cout << u << ' ' << v << '\n';
    G[u].push_back(v), G[v].push_back(u);
}

void add(int x, int y) {
    if (pos[x]) addEdge(pos[x], y);
    pos[x] = y;
    if (visit[x]) return; visit[x] = 1;
    for (int i = 0; i < 2; ++i) {
        if (!go[i][x]) continue;
        add(go[i][x], y);
    }
}

void upd(int i, int l, int r, int p, int t, int id) {
    it[0][i] += t, it[1][i] = ++cnt;
    if (!it[0][i]) it[1][i] = 0;
    if (l == r) {
        if (t == 1) pos[it[1][i]] = id; return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) upd(i << 1, l, mid, p, t, id);
    else upd(i << 1 | 1, mid + 1, r, p, t, id);
    go[0][it[1][i]] = it[1][i << 1], go[1][it[1][i]] = it[1][i << 1 | 1];
}

int get(int i, int l, int r, int u, int v, int id) {
    if (l > v || u > r) return 0;
    if (u <= l && r <= v) {
        if (it[1][i]) add(it[1][i], id);
        return it[0][i];
    }
    int mid = (l + r) >> 1;
    return get(i << 1, l, mid, u, v, id) + get(i << 1 | 1, mid + 1, r, u, v, id);
}

void dfs(int u) {
    visit[u] = 1;
    for (auto v : G[u]) {
        if (!visit[v]) dfs(v);
    }
}

void addLine(int x1, int y1, int x2, int y2) {
    a.push_back(Line(x1, y1, x2, y2));
    vx.push_back(x1), vx.push_back(x2);
    vy.push_back(y1), vy.push_back(y2);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> w >> h >> n;

    addLine(0, 0, 0, h);
    addLine(0, h, w, h);
    addLine(w, 0, w, h);
    addLine(0, 0, w, 0);

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        addLine(x1, y1, x2, y2);
    }

    n += 4, cntv = n * 2, cnte = cnt = n;
    sort(vx.begin(), vx.end()), sort(vy.begin(), vy.end());

    for (int i = 0; i < n; ++i) {
        a[i].x1 = lower_bound(vx.begin(), vx.end(), a[i].x1) - vx.begin();
        a[i].y1 = lower_bound(vy.begin(), vy.end(), a[i].y1) - vy.begin();
        a[i].x2 = lower_bound(vx.begin(), vx.end(), a[i].x2) - vx.begin();
        a[i].y2 = lower_bound(vy.begin(), vy.end(), a[i].y2) - vy.begin();

        if (a[i].y1 == a[i].y2) {
            update[a[i].x1].push_back(Update(a[i].y1, 1, i + 1));
            update[a[i].x2 + 1].push_back(Update(a[i].y2, -1, i + 1));
        }
        else {
            query[a[i].x1].push_back(Query(a[i].y1, a[i].y2, i + 1));
        }
    }

    for (int i = 0; i < n * 2; ++i) {
        for (auto j : update[i]) {
            if (j.t == -1) {
//                j.dbg();
                upd(1, 0, n * 2, j.p, j.t, j.id);
            }
        }
        for (auto j : update[i]) {
            if (j.t ==  1) {
//                j.dbg();
                upd(1, 0, n * 2, j.p, j.t, j.id);
            }
        }
        for (auto j : query[i]) {
//            j.dbg();
            int tmp = get(1, 0, n * 2, j.l, j.r, j.id);
            cntv += tmp, cnte += tmp * 2;
        }
    }
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) dfs(i), cntc++;
    }

    //cout << "End " << cntc << ' ' << cntv << ' ' << cnte << '\n';
    cout << cntc - cntv + cnte << '\n';
}