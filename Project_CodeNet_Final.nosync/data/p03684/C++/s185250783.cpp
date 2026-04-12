#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define LL long long
struct Point {
    LL x, y, id;
};
vector<Point> vecx, vecy;
bool cmpx (Point a, Point b) {
    return a.x < b.x;
}
bool cmpy (Point a, Point b) {
    return a.y < b.y;
}
struct Edge {
    LL from, to, d;
    bool operator < (const Edge &rhs) const {
        return d > rhs.d;
    }
};
LL x[maxn], y[maxn], n, ans;
vector<Edge> edges[maxn];
bool in[maxn];
priority_queue<Edge> pq;
LL cal (LL a, LL b) {
    return min (abs(x[a]-x[b]), abs(y[a]-y[b]));
}
void put_in (LL a) {
    for (LL i = 0; i < edges[a].size(); i++) {
        Edge e = edges[a][i];
        //printf ("%lld %lld %lld\n", e.from, e.to, e.d);
        pq.push (edges[a][i]);
    }
}
int main () {
    scanf ("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        scanf ("%lld%lld", &x[i], &y[i]);
        vecx.push_back ({x[i], y[i], i});
        vecy.push_back ({x[i], y[i], i});
    }
    sort (vecx.begin(), vecx.end(), cmpx);
    sort (vecy.begin(), vecy.end(), cmpy);
    for (LL i = 0; i < vecx.size(); i++) {
        if (i != 0)
            edges[vecx[i].id].push_back ({vecx[i].id, vecx[i-1].id, cal(vecx[i].id, vecx[i-1].id)});
        if (i != vecx.size()-1)
            edges[vecx[i].id].push_back ({vecx[i].id, vecx[i+1].id, cal(vecx[i].id, vecx[i+1].id)});
    }
    for (LL i = 0; i < vecy.size(); i++) {
        //printf ("%lld: %lld\n", i+1, vecy[i].id);
        if (i != 0)
            edges[vecy[i].id].push_back ({vecy[i].id, vecy[i-1].id, cal(vecy[i].id, vecy[i-1].id)});
        if (i != vecy.size()-1)
            edges[vecy[i].id].push_back ({vecy[i].id, vecy[i+1].id, cal(vecy[i].id, vecy[i+1].id)});
    }
    in[1] = true;
    put_in (1);
    while (!pq.empty()) {
        Edge e = pq.top(); pq.pop();
        if (in[e.to]) continue;
        else {
            //printf ("%lld %lld %lld\n", e.from, e.to, e.d);
            in[e.to] = true;
            put_in (e.to);
            ans += e.d;
        }
    }
    printf ("%lld\n", ans);
}
