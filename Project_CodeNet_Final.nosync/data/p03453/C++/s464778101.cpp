
// vim: set fdm=marker:
// {{{
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>

using namespace std ;

typedef long long ll ;

// }}}

#define MOD 1000000007

struct K {
  int v;
  ll d;
};

struct cmp{
    bool operator() ( K k1, K k2) {
        return k1.d > k2.d;
    }
} ;

struct sp{
    vector<ll> sd;
};

int N, M;
ll dis[111111];
bool vis[111111];

vector<pair<int, ll>> to[111111];

sp* singleSP(int orig) {
    auto ret = new sp;
    ret->sd.resize(N+1);
    memset(dis, 0x7F, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<K, vector<K>, cmp> PQ;
    PQ.push({orig, 0});
    while(PQ.size()) {
        K now;
        do {
          now = PQ.top();
          PQ.pop();
        } while(PQ.size() && vis[now.v]);
        if(!PQ.size() && vis[now.v])
            return ret;
        dis[now.v] = now.d;
        //printf("dis[%d] = %lld\n", now.v, now.d);
        ret->sd[now.v] = now.d;
        vis[now.v] = true;
        for(auto p: to[now.v]) {
            if(!vis[p.first]) {
                PQ.push({p.first, now.d+p.second});
                //printf("PQ push %d, d = %lld\n", p.first, now.d+p.second);
            }
        }
    }
    return ret;
}

struct edge{
    int first;
    int second;
    ll d;
};

ll calcComb(int now, const sp* dis, vector<ll>* out) {
    if((*out)[now] != -1)
        return (*out)[now];
    ll acc = 0;
    for(auto p: to[now]) {
        if(dis->sd[p.first] + p.second == dis->sd[now]) {
            acc += calcComb(p.first, dis, out);
            acc %= MOD;
        }
    }
    (*out)[now] = acc;
    //printf("comb %d = %lld\n", now, acc);
    return acc;
}

int main()
{
    int S, T;
    cin >> N >> M >> S >> T;
    vector<edge> es;
    for(int i = 0 ; i != M ; i++) {
        int U, V, D;
        scanf("%d%d%d", &U, &V, &D);
        to[U].push_back({V, D});
        to[V].push_back({U, D});
        es.push_back({U, V, D});
        es.push_back({V, U, D});
    }
    auto ssp = singleSP(S);
    auto tsp = singleSP(T);
    auto scomb = new vector<ll>;
    auto tcomb = new vector<ll>;
    scomb->resize(N+1, -1);
    tcomb->resize(N+1, -1);
    (*scomb)[S] = 1;
    (*tcomb)[T] = 1;
    calcComb(T, ssp, scomb);
    calcComb(S, tsp, tcomb);
    ll pd = ssp->sd[T];
    //printf("pd = %lld\n", pd);
    vector<ll> mp;
    for(auto e: es) {
        if(tsp->sd[e.first] * 2 < pd &&
           ssp->sd[e.second] * 2 < pd &&
           tsp->sd[e.first] + ssp->sd[e.second] + e.d == pd) {
          mp.push_back((*tcomb)[e.first] * (*scomb)[e.second] % MOD);
        }

    }
    for(int i = 1 ; i <= N ; i++) {
        if(tsp->sd[i] * 2 == pd &&
           ssp->sd[i] * 2 == pd)
          mp.push_back((*tcomb)[i] * (*scomb)[i] % MOD);
    }
    ll ans = 0;
    ll tot = 0;
    for(auto c: mp) {
        tot += c;
        tot %= MOD;
    }
    for(auto c: mp) {
        ans += c*(tot - c + MOD);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}

