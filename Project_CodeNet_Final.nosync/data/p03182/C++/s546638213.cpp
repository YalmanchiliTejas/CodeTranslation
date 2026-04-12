#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<long long> data, lazy;

void Add(int node, int b, int e, int l, int r, int val) {
    if (l > r) return;
    if (b == l && e == r) {
        lazy[node] += val;
        return;
    }
    
    int m = (b + e) / 2;
    Add(node * 2, b, m, l, min(r, m), val);
    Add(node * 2 + 1, m + 1, e, max(l, m + 1), r, val);
    data[node] = max(data[node * 2] + lazy[node * 2],  
            data[node * 2 + 1] + lazy[node * 2 + 1]);
}

long long Get() {
    return max(0LL, data[1] + lazy[1]);
}

int32_t main() {

    int n, m; cin >> n >> m;
    lazy.resize(4 * n, 0);
    data.resize(4 * n, 0);

    vector<tuple<int, int, int>> segs;
    for (int i = 0; i < m; ++i) {
        int l, r, w; cin >> l >> r >> w; --l; --r;
        segs.emplace_back(r, l, w);
    } 

    sort(segs.begin(), segs.end());

    vector<long long> dp(n, 0);


    int at = 0;
    for (int i = 0; i < n; ++i) {
        while (at < m && get<0>(segs[at]) < i) {
            int l, r, w; tie(r, l, w) = segs[at++];
            Add(1, 0, n - 1, l, r, w);
        }
        Add(1, 0, n - 1, i, i, Get());
    }
    while (at < m) {
        int l, r, w; tie(r, l, w) = segs[at++];
        Add(1, 0, n - 1, l, r, w);
    }

    cout << Get() << endl;


    return 0;
}
