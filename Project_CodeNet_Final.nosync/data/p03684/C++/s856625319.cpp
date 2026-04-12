#include "bits/stdc++.h"
using namespace std;


const int N = 1e5 + 5;
int link[N], size[N];

int find(int a) {
    return a == link[a] ? a : link[a] = find(link[a]);
}

bool same(int a, int b) {
    return find(a) == find(b);
}


void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(size[a] < size[b]) swap(a, b);
    size[a] += size[b];
    link[b] = a;
}


int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) link[i] = i, size[i] = 1;

    vector< pair< int, int> > x, y;
    x.reserve(n);
    y.reserve(n);

    for(int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        x.emplace_back(a, i);
        y.emplace_back(b, i);
    }

    sort(begin(x), end(x));
    sort(begin(y), end(y));

    vector< tuple< int, int, int> > Vt;
    Vt.reserve(2 * n);
    for(int i = 0; i < n - 1; i++) {
        Vt.push_back(make_tuple(x[i + 1].first - x[i].first, x[i].second, x[i + 1].second));
        Vt.push_back(make_tuple(y[i + 1].first - y[i].first, y[i].second, y[i + 1].second));
    }

    sort(begin(Vt), end(Vt));
    long long res = 0;
    for(auto it: Vt) {
        int u, v, w;
        tie(w, u, v) = it;
        if(same(u, v)) continue;
        unite(u, v);
        res += w;
    }

    cout << res << endl;

}