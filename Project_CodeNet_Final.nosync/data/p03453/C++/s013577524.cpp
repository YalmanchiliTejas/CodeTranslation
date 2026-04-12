#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL, int> P;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int pw2(int x) {
    return mul(x,x);
}

vector<P> g[maxn];
LL ds[maxn], dt[maxn];
int fs[maxn], ft[maxn], p[maxn];
set<P> q;

bool cmp1(const int a, const int b) {
    return ds[a] < ds[b];
}
bool cmp2(const int a, const int b) {
    return dt[a] < dt[b];
}

void dij(int s, LL d[]) {
    for(int i = 0; i < maxn; i++) d[i] = 1LL * mod * mod;
    d[s] = 0;
    q.clear();
    q.insert(P(0, s));
    while(!q.empty()) {
        P e = *q.begin();
        q.erase(e);
        int u = e.se;
        LL w = e.fi;
        for(auto v : g[u]) {
            if(d[v.se] > w + v.fi) {
                q.erase(P(d[v.se], v.se));
                d[v.se] = w + v.fi;
                q.insert(P(d[v.se], v.se));
            }
        }
    }
}

int main() {
#ifdef CX_TEST
    freopen("E:\\program--GG\\test_in.txt", "r", stdin);
#endif
    int n, m, s, t, i, j, u, v, w;
    scanf("%d%d", &n, &m);
    scanf("%d%d", &s, &t);
    for(i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(P(w, v));
        g[v].push_back(P(w, u));
    }
    dij(s, ds);
    dij(t, dt);
    if(ds[t] > 1e18) return puts("0"), 0;
    LL dis = ds[t];
    for(i = 0; i < n; i++) p[i] = i + 1;
    sort(p, p + n, cmp1);
    fs[s] = 1;
    for(i = 0; i < n; i++) {
        for(auto e : g[p[i]]) {
            if(ds[p[i]] + dt[e.se] + e.fi == dis) fs[e.se] = add(fs[e.se], fs[p[i]]);
        }
        //cout<<p[i]<<" "<<fs[p[i]]<<endl;
    }
    //cout<<"============"<<endl;
    sort(p, p + n, cmp2);
    ft[t] = 1;
    for(i = 0; i < n; i++) {
        for(auto e : g[p[i]]) {
            if(dt[p[i]] + ds[e.se] + e.fi == dis) ft[e.se] = add(ft[e.se], ft[p[i]]);
        }
       // cout<<p[i]<<" "<<ft[p[i]]<<endl;
    }
    //cout<<fs[t]<<" "<<ft[s]<<endl;
    int ans = mul(fs[t], ft[s]);
    for(i = 1; i <= n; i++) {
        if(ds[i] + dt[i] == dis) {
            if(ds[i] == dt[i]) ans = add(ans, mod - pw2(mul(fs[i], ft[i])));
            for(auto e : g[i]) {
                if(ds[i] + dt[e.se] + e.fi == dis && abs(ds[i] - dt[e.se]) < e.fi) ans = add(ans, mod - pw2(mul(fs[i], ft[e.se])));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
