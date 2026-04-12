#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <iterator>
#include <random>
#include <fstream>
#include <chrono>
#include <math.h>
#include <cctype>
using namespace std;
#define int long long
#define forn(i, n) for (int i = 0; i < n; ++i)
const int tree_size = (1 << 19);
int n, m;
vector<int> l;
vector<vector<pair<int, int>>> r;
vector<int> mx(tree_size, -2e18);
vector<int> buf(tree_size, 0);

void upd(int v, int l, int r) {
    // нам нужно обновить mx
    // update хочет чтоб в v !было буф
    // наст значеение то что нап в mx + buf[от корня до вершины вкл]
    mx[v] = mx[v] + buf[v];
    if (l < r - 1) {
        buf[2 * v + 1] += buf[v];
        buf[2 * v + 2] += buf[v];
    }
    buf[v] = 0;
}

int get_max(int v, int l, int r, int L, int R) { // l , r - границы L,R запрос
    upd(v, l, r);
    if(R <= l || L >= r)
        return -2e18;
    if(L <= l && r <= R)
        return mx[v];
    int m = (r + l)/2;
    return max(
            get_max(2*v+1, l, m, L, R),
            get_max(2*v+2, m, r, L, R)
    );
}

void relax(int v, int l, int r, int i, int x) {
    upd(v, l, r);
    mx[v] = max(mx[v], x);
    if (r-l==1)
        return;
    int m = (l + r)/2;
    if(i < m)
        relax(2*v+1, l , m, i , x);
    else
        relax(2 * v + 2, m, r, i, x);
}

void add_seg(int v, int l, int r, int L, int R, int x) {
    upd(v, l ,r);
    if(R <= l || L >= r)
        return;
    if(L <= l && r <= R) {
        buf[v]+=x;
        upd(v, l, r);
        return;
    }
    int m = (r + l)/2;
    add_seg(2*v+1, l, m, L, R, x);
    add_seg(2*v+2, m, r, L, R, x);
    mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    l.resize(n);
    r.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        l[x] += c;
        r[y].push_back({x, c});
    }
    relax(0, -1, n, -1, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        add_seg(0, -1, n, -1, i, l[i]);
        for (auto seg: r[i]) {
            add_seg(0, -1, n, -1, seg.first, -seg.second);
        }
        int cur = mx[0];
        ans = max(ans, cur);
        relax(0, -1, n, i, cur);
    }
    cout << ans << endl;
    return 0;
}