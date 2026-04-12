#pragma region include
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <cstdio>
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define MOD 1000000007
#define INF 1000000000
#define LLINF 4000000000000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#pragma endregion

//#define __DEBUG__
#ifdef  __DEBUG__
#define dump(x) cerr << #x << " = " << (x) << " [" << __LINE__ << ":" << __FUNCTION__ << "] " << endl;
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& v) {
    os << "{";
    REP(i, (int)v.size()) { os << v[i] << (i < v.size() - 1 ? ", " : ""); }
    os << "}";
    return os;
}
// pair出力
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
// map出力
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
    os << "{";
    for (auto itr = map_var.begin(); itr != map_var.end(); itr++) {
        os << "(" << itr->first << ", " << itr->second << ")";
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set 出力
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
    os << "{";
    for (auto itr = set_var.begin(); itr != set_var.end(); itr++) {
        os << *itr;
        ++itr;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
#endif

struct Point{
    int index;
    PII p;
};

struct Points {
    int dist;
    Point a, b;
};

//UnionFind
class UnionFind {
private:
    vector<int> par;
public:
    UnionFind(int n) {
        par = vector<int>(n, -1);
    }

    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        if (size(rx) < size(ry)) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

bool operator<(const Points &x, const Points &y) {
    return x.dist > y.dist;
}

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int N; cin >> N;
    ll ans = 0;
    vector<Point> point1(N),point2(N);
    REP(i, N) {
        point1[i].index = i;
        cin >> point1[i].p.first >> point1[i].p.second;
        point2[i] = point1[i];
    }
    sort(ALL(point1), [](const Point& x, const Point& y) { return x.p.first < y.p.first; });
    sort(ALL(point2), [](const Point& x, const Point& y) { return x.p.second < y.p.second; });
    priority_queue<Points> pq;
    REP(i, N-1) {
        Point p11 = point1[i], p12 = point1[i + 1];
        Point p21 = point2[i], p22 = point2[i + 1];
        pq.push(Points{min(abs(p11.p.first - p12.p.first),abs(p11.p.second - p12.p.second)),p11,p12});
        pq.push(Points{min(abs(p21.p.first - p22.p.first),abs(p21.p.second - p22.p.second)),p21,p22});
    }
    UnionFind uni(N);
    while (!pq.empty()) {
        Points ps = pq.top(); pq.pop();
        if (uni.same(ps.a.index, ps.b.index)) continue;
        uni.unite(ps.a.index, ps.b.index);
        ans += ps.dist;
    }
    cout << ans << endl;
    getchar(); getchar();
}