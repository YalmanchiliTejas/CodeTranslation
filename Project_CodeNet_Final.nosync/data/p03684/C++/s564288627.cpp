#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> PII;
typedef pair<PII, int> PPI;
typedef pair<int, PII> PIP;

const int MAXN = 1000000 + 10;
int n;
int a[MAXN];

pair<int,int> p[MAXN];

int dist(int a, int b) {
    return min(abs(p[a].first - p[b].first), abs(p[a].second - p[b].second));
}

vector<PIP> edges;
int par[MAXN], siz[MAXN];


int fi(int x) {
    if (par[x] != par[par[x]])
        par[x] = fi(par[x]);
    return par[x];
}

int uni(int a, int b) {
    a = fi(a);
    b = fi(b);

    if (a == b) return 0;

    if (siz[a] > siz[b]) {
        siz[a] += siz[b];
        par[b] = a;
    } else {
        siz[b] += siz[a];
        par[a] = b;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin >> n;

    vector<pair<pair<int,int>, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        v.push_back({p[i], i});
    }

    sort(begin(v), end(v), [](PPI a, PPI b) { return a.first.first < b.first.first; });
    for (int i = 0; i + 1 < v.size(); i++) {
        int a = v[i].second;
        int b = v[i+1].second;
        edges.push_back({dist(a, b), {a, b}});
    }
    sort(begin(v), end(v), [](PPI a, PPI b) { return a.first.second < b.first.second; });
    for (int i = 0; i + 1 < v.size(); i++) {
        int a = v[i].second;
        int b = v[i+1].second;
        edges.push_back({dist(a, b), {a, b}});
    }
    sort(begin(edges), end(edges));


    for (int i = 0; i < n; i++) {
        siz[i] = 1;
        par[i] = i;
    }
    int res = 0;
    for (int i = 0; i < edges.size(); i++) {
        int d = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;

        if (fi(a) != fi(b)) {
            uni(a, b);
            res += d;
        }
    }

    cout << res << "\n";
    return 0;
}
