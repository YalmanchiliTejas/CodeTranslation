#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
P x[100010], y[100010];

class UnionFind {
private:
    static const int MAX = 100010;
    int par[MAX];
    int r[MAX];
public:
    UnionFind(int n = MAX) {
        for (int i = 0; i < n; i++) {
            par[i] = i;
            r[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (r[x] < r[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (r[x] == r[y]) r[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
typedef pair<ll, P> PP;
ll solve() {
    sort(x, x+n);
    sort(y, y+n);

    vector<PP> vec;
    for (int i = 0; i < n-1; i++) {
        vec.push_back(PP(x[i+1].first - x[i].first, P(x[i+1].second, x[i].second)));
        vec.push_back(PP(y[i+1].first - y[i].first, P(y[i+1].second, y[i].second)));
    }

    sort(ALL(vec));
    UnionFind uf(n);
    ll res = 0;
    for (int i = 0; i < vec.size(); i++) {
        int a = vec[i].second.first;
        int b = vec[i].second.second;
        if (!uf.same(a, b)) {
            res += vec[i].first;
            uf.unite(a, b);
        }
    }
    return res;
}

void input() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        x[i] = P(a, i);
        y[i] = P(b, i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
