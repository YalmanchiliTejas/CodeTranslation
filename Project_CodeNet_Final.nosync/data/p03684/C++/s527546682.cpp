#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = int64_t;

const int LIM = 100000;

struct union_find {
    int par[LIM];

    union_find() { fill(par, par+LIM, -1); }

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    bool unify(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return false;
        if (par[xx] < par[yy]) {
            par[xx] += par[yy];
            par[yy] = xx;
        } else {
            par[yy] += par[xx];
            par[xx] = yy;
        }
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -par[find(x)];
    }
};

struct edge {
    int x, y, cost;
    edge() {}
    edge(int a, int b, int c): x(a), y(b), cost(c) {}

    bool operator < (const edge& o ) const {
        return cost > o.cost;
    }
};

int N;

vector<pair<int, i64> > arx, ary;


int main() {
    cin >> N;
    for (int j = 0; j < N; ++j) {
        i64 x, y;
        cin >> x >> y;
        arx.emplace_back(x, j);
        ary.emplace_back(y, j);
    }
    sort(begin(arx), end(arx));
    sort(begin(ary), end(ary));

    priority_queue<edge> pqx, pqy;

    for (int j = 0; j < N-1; ++j) {
        pqx.emplace(arx[j].second, arx[j+1].second, abs(arx[j].first - arx[j+1].first));
        pqy.emplace(ary[j].second, ary[j+1].second, abs(ary[j].first - ary[j+1].first));
    }

    union_find uf;
    i64 ans = 0;

    while (uf.size(0) < N) {
        assert(!pqx.empty() && !pqy.empty());
        edge ex = pqx.top(), ey = pqy.top();

        if (!uf.same(ex.x, ex.y) && ex.cost <= ey.cost) {
            ans += ex.cost;
            uf.unify(ex.x, ex.y);
        } else if (!uf.same(ey.x, ey.y) && ey.cost <= ex.cost) {
            ans += ey.cost;
            uf.unify(ey.x, ey.y);
        }

        if (uf.same(ex.x, ex.y)) {
            pqx.pop();
        }
        if (uf.same(ey.x, ey.y)) {
            pqy.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
