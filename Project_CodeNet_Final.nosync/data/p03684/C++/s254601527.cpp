#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

#ifdef ZTDebug
#define In scanf_s
#else
#define In scanf
#endif // ZTDebug

#define Ind(d) In("%d", &d)
#define Ind2(a, b) In("%d%d", &a, &b)
#define InD(d) int d; In("%d", &d);
#define InD2(a, b) int a, b; In("%d%d", &a, &b);
#define InDN(n, v) for (auto _i = 0; _i < n; ++_i) In("%d", &v[_i]);
#define OutDNLine(n, v) for (auto _i = 0; _i < n; ++_i) printf("%d%c", *(v + _i), _i + 1 == n ? '\n' : ' ');

typedef double db;
typedef long long LL;
typedef pair<int, int> pii;

const int Max = 100010;

int fa[Max], xs[Max], ys[Max];
int getFa(int x) { return fa[x] == -1 ? x : fa[x] = getFa(fa[x]); }

bool cmpX(int i, int j) { return xs[i] < xs[j]; }
bool cmpY(int i, int j) { return ys[i] < ys[j]; }

int main() {
#ifdef ZTDebug
    while (true) {
#endif // ZTDebug
        InD(n);
        for (auto i = 0; i < n; ++i) Ind2(xs[i], ys[i]);

        memset(fa, -1, sizeof(fa));
        vector<int> vec;
        for (auto i = 0; i < n; ++i) vec.push_back(i);

        vector<tuple<int, int, int>> edges;
        sort(vec.begin(), vec.end(), cmpX);
        for (auto i = 1; i < n; ++i) edges.push_back(make_tuple(xs[vec[i]] - xs[vec[i - 1]], vec[i], vec[i - 1]));
        sort(vec.begin(), vec.end(), cmpY);
        for (auto i = 1; i < n; ++i) edges.push_back(make_tuple(ys[vec[i]] - ys[vec[i - 1]], vec[i], vec[i - 1]));

        sort(edges.begin(), edges.end());

        auto sum = 0;
        for (auto e : edges) {
            auto fx = getFa(get<1>(e)), fy = getFa(get<2>(e));
            if (fx != fy) {
                fa[fx] = fy;
                sum += get<0>(e);
            }
        }
        cout << sum << endl;
#ifdef ZTDebug
    }
#endif // ZTDebug
    return 0;
}
