
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

constexpr static int MAXN = 2e5;

int n;
int x[MAXN], y[MAXN];
unordered_map <int, vector <int>> xval, yval;

int64_t total = 0;
int p[MAXN], r[MAXN];

int f(int a) {
    if (p[a] != a)
        p[a] = f(p[a]);
    return p[a];
}

void merge(int a, int b) {
    int ar = f(a);
    int br = f(b);
    if (ar == br)
        return;
    if (r[ar] < r[br])
        p[ar] = br;
    else if (r[ar] > r[br])
        p[br] = ar;
    else {
        p[br] = ar;
        r[ar] = r[ar] + 1;
    }
    total += min(abs(x[a] - x[b]), abs(y[a] - y[b]));
}

void add_edge(int u, int v) {
    if (f(u) == f(v))
        merge(u, v);
}

int main() {
    cin >> n;
    set <int> xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        xs.insert(x[i]);
        ys.insert(y[i]);
        xval[x[i]].push_back(i);
        yval[y[i]].push_back(i);
    }
    vector <int> xv(xs.begin(), xs.end());
    vector <int> yv(ys.begin(), ys.end());

    vector <pair <int, pair <int, int>>> edges;
    for (int i = 0; i + 1 < xv.size(); i++)
        edges.push_back({xv[i + 1] - xv[i], {i, 0}});
    for (int i = 0; i + 1 < yv.size(); i++)
        edges.push_back({yv[i + 1] - yv[i], {i, 1}});
    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++) {
        p[i] = i;
        r[i] = 0;
    }
    for (auto& kv : xval)
        for (int i = 0; i + 1 < kv.second.size(); i++)
            merge(kv.second[i], kv.second[i + 1]);
    for (auto& kv : yval)
        for (int i = 0; i + 1 < kv.second.size(); i++)
            merge(kv.second[i], kv.second[i + 1]);
    for (auto& e : edges) {
        vector <int> v1, v2;
        if (e.second.second == 0) {
            int i = e.second.first;
            v1 = xval[xv[i]];
            v2 = xval[xv[i + 1]];
        }
        else {
            int i = e.second.first;
            v1 = yval[yv[i]];
            v2 = yval[yv[i + 1]];
        }
        for (int i : v1)
            merge(i, v2[0]);
        for (int i : v2)
            merge(i, v1[0]);
    }

    cout << total << endl;
}
