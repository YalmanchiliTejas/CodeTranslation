
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

constexpr static int MAXN = 2e5;

int n;
int x[MAXN], y[MAXN];

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

int main() {
    cin >> n;
    vector <pair <int, int>> xv, yv;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        xv.push_back({x[i], i});
        yv.push_back({y[i], i});
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());
    vector <pair <int, pair <int, int>>> edges;
    for (int i = 0; i + 1 < n; i++) {
        edges.push_back({xv[i + 1].first - xv[i].first, {xv[i].second, xv[i + 1].second}});
        edges.push_back({yv[i + 1].first - yv[i].first, {yv[i].second, yv[i + 1].second}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++)
        p[i] = i;
    for (auto& e : edges)
        merge(e.second.first, e.second.second);
    cout << total << endl;
}
