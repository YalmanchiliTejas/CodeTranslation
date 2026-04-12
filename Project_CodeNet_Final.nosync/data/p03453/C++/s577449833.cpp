//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//ifstream cin("x.in"); ofstream cout("x.out");

typedef long long i64;
const int nmax = 1e5;
const i64 inf = (1LL << 60);
const int mod = 1e9 + 7;

int n;
vector<pair<int, int>> g[nmax + 1];
bool gata[nmax + 1];
i64 d[ 2 ][nmax + 1];
int c[ 2 ][nmax + 1];

struct muchie {
    int x, y, c;
};
vector< muchie > w;

struct str {
    int x; i64 dst;

    str () {}
    str (int _x, i64 _dst) {
        x = _x, dst = _dst;
    }

    inline bool operator < (const str &shp) const {
        if (dst != shp.dst)
            return (dst > shp.dst);
        return (x > shp.x);
    }
};
priority_queue< str > h;

void extinde (str k, int ind) {
    for (auto i : g[ k.x ]) {
        if (gata[ i.first ] == 1)
            continue;

        if (d[ ind ][ i.first ] > k.dst + i.second) {
            d[ ind ][ i.first ] = k.dst + i.second;
            h.push(str(i.first, d[ ind ][ i.first ]));
        }
    }
}

void afla_c (str k, int ind) {
    for (auto i : g[ k.x ]) {
        if (d[ ind ][ i.first ] + i.second == k.dst) {
            c[ ind ][ k.x ] += c[ ind ][ i.first ];

            if (c[ ind ][ k.x ] >= mod)
                c[ ind ][ k.x ] -= mod;
        }
    }
}

void dijkstra (int sursa, int ind) {
    for (int i = 1; i <= n; ++ i)
        d[ ind ][ i ] = inf;

    memset(gata, 0, sizeof(gata));
    h.push(str(sursa, 0));
    d[ ind ][ sursa ] = 0;
    c[ ind ][ sursa ] = 1;

    while (!h.empty()) {
        str x = h.top();
        h.pop();

        if (gata[ x.x ] == 1)
            continue;

        gata[ x.x ] = 1;
        extinde(x, ind);

        if (x.x != sursa)
            afla_c(x, ind);
    }
}

int main() {
    int m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; ++ i) {
        int x, y, cst;
        cin >> x >> y >> cst;

        g[ x ].push_back(make_pair(y, cst));
        g[ y ].push_back(make_pair(x, cst));

        muchie aux;
        aux.x = x; aux.y = y; aux.c = cst;
        w.push_back( aux );
    }

    dijkstra(s, 0);
    dijkstra(t, 1);

    long long ans = 1LL * c[ 0 ][ t ] * c[ 0 ][ t ] % mod;

    for (int i = 1; i <= n; ++ i) {
        /// pp se intalnesc fix in i
        if (d[ 0 ][ i ] == d[ 1 ][ i ] && d[ 0 ][ i ] + d[ 1 ][ i ] == d[ 0 ][ t ]) {
            long long alegi = 1LL * c[ 0 ][ i ] * c[ 1 ][ i ] % mod;

            ans = (ans - alegi * alegi) % mod;
            if (ans < 0)
                ans += mod;
        }
    }

    for (auto i : w) {
        int x = i.x, y = i.y;
        if (d[ 0 ][ x ] > d[ 0 ][ y ])
            swap(x, y);

        if (d[ 0 ][ x ] + i.c + d[ 1 ][ y ] != d[ 0 ][ t ])
            continue;

        if (abs(d[ 0 ][ x ] - d[ 1 ][ y ]) >= i.c) // nu se intalensc pe muchie
            continue;

        long long alegm = 1LL * c[ 0 ][ x ] * c[ 1 ][ y ] % mod;

        ans = (ans - alegm * alegm) % mod;
        if (ans < 0)
            ans += mod;
    }

    cout << ans << "\n";

    return 0;
}
