
#include<bits/stdc++.h>
using namespace std;
#define D(x)    cout << #x " = " << (x) << endl
#define cost    first
#define xx      second.first
#define yy      second.second
#define MAX     100000
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef long long int LL;

vector< piii > edge;
vector<piii> on_x, on_y;

namespace std{
    bool cmp (const piii &u, const piii & v){ return u.xx < v.xx;}
}

int par[MAX+5];

int find_par(int idx)
{
    if(par[idx] == idx) return idx;
    return par[idx] = find_par(par[idx]);
}

bool join(int u, int v)
{
    int pu = find_par(u);
    int pv = find_par(v);
    if(pu == pv) return false;
    par[pu] = pv;
    return true;
}

int main()
{
    int i, j, k, n, x, y;
    LL res = 0;

    scanf("%d", &n);
    for(i = 1; i <= n; i++) par[i] = i;

    for(i = 1; i <= n; i++)
    {
        scanf("%d %d", &x, &y);
        on_x.push_back(piii(i, pii(x,y)));
        on_y.push_back(piii(i, pii(y,x)));
    }

    sort(on_x.begin(), on_x.end(), cmp);
    sort(on_y.begin(), on_y.end(), cmp);

    for(i = 1; i < (int) on_x.size(); i++) edge.push_back(piii(on_x[i].xx - on_x[i-1].xx, pii(on_x[i].first, on_x[i-1].first)));
    for(i = 1; i < (int) on_y.size(); i++) edge.push_back(piii(on_y[i].xx - on_y[i-1].xx, pii(on_y[i].first, on_y[i-1].first)));

    sort(edge.begin(), edge.end());
    for(auto e : edge)
        if(join(e.xx, e.yy))
            res += e.cost;

    cout << res << endl;
    return 0;
}
