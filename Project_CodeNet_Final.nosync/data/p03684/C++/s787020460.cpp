#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <unordered_set>
#include <unordered_map>

using namespace std;

#define all(c) ((c).begin()), ((c).end())
#define dump(c) cerr << "> " << #c << " = " << (c) << endl;
#define iter(c) __typeof((c).begin())
#define tr(i, c) for (iter(c) i = (c).begin(); i != (c).end(); i++)
#define REP(i, a, b) for (int i = a; i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back
#define debug( fmt, ... ) \
        fprintf( stderr, \
                  fmt "\n", \
                  ##__VA_ARGS__ \
        )

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1 << 30;
const double EPS = 1e-10;

double zero(double d) {
    return abs(d) < EPS ? 0.0 : d;
}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    return os << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    rep(i, a.size()) os << (i ? " " : "") << a[i];
    return os << ']';
}

string toString(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
}

const int MOD = 1000000007;
// a^k
ll fpow(ll a, ll k, int M) {
    ll res = 1ll;
    ll x = a;
    while (k != 0) {
        if ((k & 1) == 1)
            res = (res * x) % M;
        x = (x * x) % M;
        k >>= 1;
    }
    return res;
}

struct prepare {
	prepare() {
	    cout.setf(ios::fixed, ios::floatfield);
	    cout.precision(8);
	    ios_base::sync_with_stdio(false);
	}
} _prepare;

struct Edge {
    int u;
    int v;
    int cost;
};

bool comp(const Edge& e1, const Edge& e2) {
    return e1.cost < e2.cost;
}


class UnionFind {
private:
    vi par;
    vi rank;

    int find(int x) {
        if(par[x] == x)
            return x;
        else
            return par[x] = find(par[x]);
    }

public:
    UnionFind(int n) {
        rep(i,n) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x==y) return;

        if(rank[x] < rank[y])
            par[x] = y;
        else {
            par[y] = x;
            if(rank[x] == rank[y])
                rank[x]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int cost(pii a, pii b) {
    return min(abs(a.first - b.first), abs(a.second - b.second));
}

bool solve() {
    int N;
    cin >> N;

    vector<pair<pii, int>> xf(N), yf(N);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        xf[i] = mp(mp(x, y), i);
        yf[i] = mp(mp(y, x), i);
    }

    sort(all(xf));
    sort(all(yf));

    vector<Edge> edges;
    rep(i, N) {
        if(i != 0) {
            int c = cost(xf[i-1].first, xf[i].first);
            edges.push_back(Edge{ xf[i-1].second, xf[i].second, c });
            edges.push_back(Edge{ xf[i].second, xf[i-1].second, c });

            int c2 = cost(yf[i-1].first, yf[i].first);
            edges.push_back(Edge{ yf[i-1].second, yf[i].second, c2 });
            edges.push_back(Edge{ yf[i].second, yf[i-1].second, c2 });
        }
        if(i != N-1) {
            int c = cost(xf[i].first, xf[i+1].first);
            edges.push_back(Edge{ xf[i].second, xf[i+1].second, c });
            edges.push_back(Edge{ xf[i+1].second, xf[i].second, c });

            int c2 = cost(yf[i].first, yf[i+1].first);
            edges.push_back(Edge{ yf[i].second, yf[i+1].second, c2 });
            edges.push_back(Edge{ yf[i+1].second, yf[i].second, c2 });
        }
    }

    sort(all(edges), comp);

    UnionFind uf(N);
    int res = 0;
    tr(it, edges) {
        if(!uf.same(it->u, it->v)) {
            uf.unite(it->u, it->v);
            res += it->cost;
        }
    }

    cout << res << endl;
}

int main() {
    auto res = solve();	
	
    return 0;
}
