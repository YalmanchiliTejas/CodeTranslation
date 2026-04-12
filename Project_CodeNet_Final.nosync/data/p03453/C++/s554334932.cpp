#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 100010;
const int maxm = 200010;
const int mod = 1e9+7;

typedef long long ll;

struct node {
    int u, v, w;
} T[maxm*2];

struct Edge {
    int v, w, x;
} E[maxm*2];

struct Ele {
    int id; ll d;
    Ele(int id_ = 0, ll d_ = 0) : id(id_), d(d_) {}
};

struct cmp {
    bool operator()(const Ele &a, const Ele &b) {return a.d > b.d;}
};

priority_queue<Ele, vector<Ele>, cmp> q;
int n, m, s1, t1, e, l[maxn], v[maxn];
ll dis1[maxn], dis2[maxn], cnt1[maxn], cnt2[maxn];

void insert(int u, int v, int w) {
    E[e].v = v, E[e].x = l[u], E[e].w = w, l[u] = e++;
}

void dijks1ra(int s,ll dis[],ll cnt[]) {
    for(int i = 1; i <= n; i++) dis[i] = 2e18, cnt[i] = 0;
    memset(v, 0, sizeof(v));
    dis[s] = 0;
    cnt[s] = 1;
    q.push(Ele(s, 0));
    while (!q.empty()) {
        Ele x = q.top(); q.pop();
        if (v[x.id]) continue;
        v[x.id] = 1;
        for(int p = l[x.id]; p >= 0; p = E[p].x) {
            if (x.d+E[p].w < dis[E[p].v]) {
                dis[E[p].v] = x.d + E[p].w;
                cnt[E[p].v] = cnt[x.id];
                q.push(Ele(E[p].v, dis[E[p].v]));
            } else {
                if (x.d+E[p].w == dis[E[p].v]) cnt[E[p].v] = (cnt[E[p].v]+cnt[x.id])%mod;
            }
        }
    }
}

int main() {
    memset(l, -1, sizeof(l));
    scanf("%d%d%d%d", &n, &m, &s1, &t1);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        insert(u, v, w); insert(v, u, w);
        T[i].u = u; T[i].v = v; T[i].w = w;
        T[i+m].u = v; T[i+m].v = u; T[i+m].w = w;
    }
    dijks1ra(s1, dis1, cnt1); dijks1ra(t1, dis2, cnt2);
    ll ans = cnt1[t1]*cnt2[s1] % mod;
    for (int i = 1; i <= n; i++) {
        if (dis1[i] == dis2[i] && 2*dis1[i] == dis1[t1]) {
            ll t = cnt1[i] * cnt2[i] % mod; t = t * t % mod;
            ans = ((ans-t)%mod+mod)%mod;
        }
    }
    for (int i = 1; i <= (m<<1); i++) {
        int u = T[i].u, v = T[i].v, w = T[i].w;
        if (dis1[u]*2 < dis1[t1] && dis1[v]*2 > dis1[t1] && dis1[u]+dis2[v]+w == dis1[t1]) {
            ll t = cnt1[u]*cnt2[v] % mod; t = t * t % mod;
            ans = ((ans-t)%mod+mod) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}
