#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

pair <int, int> vx[MAXN + 1];
pair <int, int> vy[MAXN + 1];

struct Edge {
    int x;
    int y;
    int cost;
    bool operator <(const Edge &other) const{
         return cost < other.cost;
    }
}g[MAXN * 2 + 1];

int sef[2 * MAXN + 1];

int myfind(int nod) {
     if(sef[nod] == 0)
        return nod;
     return sef[nod] = myfind(sef[nod]);
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i,n;
    long long x,y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> x >> y;
        vx[i].first = x;
        vx[i].second = i;
        vy[i].first = y;
        vy[i].second = i;
    }
    sort(vx + 1, vx + n + 1);
    sort(vy + 1, vy + n + 1);
    int sz = 0;
    for(i = 1; i < n; i++)
        g[++sz] = {vx[i].second, vx[i + 1].second, vx[i + 1].first - vx[i].first};
    for(i = 1; i < n; i++)
        g[++sz] = {vy[i].second, vy[i + 1].second, vy[i + 1].first - vy[i].first};
    sort(g + 1, g + sz + 1);
    long long ans = 0;
    for(i = 1; i <= sz; i++)
        if(myfind(g[i].x) != myfind(g[i].y)) {
            sef[myfind(g[i].x)] = myfind(g[i].y);
            ans += g[i].cost;
        }
    cout << ans << endl;
    //cin.close();
    //cout.close();
    return 0;
}
