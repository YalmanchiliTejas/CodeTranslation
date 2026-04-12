#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <utility>
#include <set>

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;

struct Data {
    int cost;
    int x;
    int y;
    Data(int c, int x, int y) : cost(c), x(x), y(y) {}
};

bool operator<(Data d1, Data d2) {
    return d1.cost < d2.cost;
}

class UnionFind {
private:
    int N;
    vector<int> parents;
public:
    UnionFind(int n) : N(n) {
        parents.resize(N);
        REP (i, 0, N) parents[i] = i;
    }

    int Find(int x) {
        if (x == parents[x]) return x;
        else return parents[x] = Find(parents[x]);
    }

    void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        parents[px] = py;
    }

    bool isSame(int x, int y) {
        return Find(x) == Find(y);
    }


};

int main () {
    int N;
    cin >> N;
    vector<pii> x;
    vector<pii> y;
    x.reserve(N);
    y.reserve(N);
    set<pii> s;
    REP (i, 0, N) {
        int xx, yy;
        cin >> xx >> yy;
        if (s.count(make_pair(xx, yy)) == 0) {
            x.push_back(make_pair(xx, s.size()));
            y.push_back(make_pair(yy, s.size()));
            s.insert(make_pair(xx, yy));
        }
    }
    N = s.size();
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<Data> Edge;

    REP (i, 0, N) {
        auto itx = lower_bound(x.begin(), x.end(), x[i]);
        int index = distance(x.begin(), itx);
        if (index != 0) {
            Edge.push_back(Data(x[index].first - x[index - 1].first, x[index - 1].second, x[index].second));
        }
        if (index != N - 1) {
            Edge.push_back(Data(x[index + 1].first - x[index].first, x[index + 1].second, x[index].second));
        }

        auto ity = lower_bound(y.begin(), y.end(), y[i]);
        index = distance(y.begin(), ity);
        if (index != 0) {
            Edge.push_back(Data(y[index].first - y[index - 1].first, y[index - 1].second, y[index].second));
        }
        if (index != N - 1) {
            Edge.push_back(Data(y[index + 1].first - y[index].first, y[index + 1].second, y[index].second));
        }
    }
    sort(Edge.begin(), Edge.end());
    lli cost = 0;
    UnionFind uf(N);
    REP (i, 0, Edge.size()) {
        auto e = Edge[i];
        if (!uf.isSame(e.x, e.y)) {
            cost += e.cost;
            uf.Union(e.x, e.y);
        }
    }
    cout << cost << endl;
    return 0;
}
