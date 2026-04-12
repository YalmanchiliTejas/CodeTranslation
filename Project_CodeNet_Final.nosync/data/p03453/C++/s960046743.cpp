#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <limits.h>
#include <float.h>
#include <numeric>
#include <queue>
#include <typeinfo>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define fs first
#define sc second

const ll mod = 1000000007;
ll fact[200200];
ll invfact[200200];

inline ll take_mod(ll a){
    return (a % mod + mod) % mod;
}

inline ll add(ll a, ll b){
    return take_mod(a+b);
}

inline ll sub(ll a, ll b){
    return take_mod(a-b);
}


inline ll mul(ll a, ll b){
    return take_mod(a * b);
}

inline ll pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = mul(res, x);
        x = mul(x, x);
        n >>= 1;
    }
    return res;
}

ll mod_inv(ll x){
    return pow(x, mod-2);
}

// nは上限
void make_fact(ll n){
    fact[0] = 1;
    ll res = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = res;
        res = mul(res, i+1);
    }
}

// nは上限
void make_invfact(ll n){
    invfact[0] = 1;
    invfact[n] = mod_inv(fact[n]);
    for(int i = n-1; i >= 1; i--){
        invfact[i] = mul(invfact[i + 1], i + 1);
    }
}

ll perm(ll n, ll k){
    return mul(fact[n], invfact[n-k]);
}

ll comb(ll n, ll k){
    return mul(mul(fact[n], invfact[n-k]), invfact[k]);
}

#define MAX_V 201000
#define INF LONG_LONG_MAX

class edge{
public:
    int to; ll cost;
    edge(int x, ll y){
        to = x;
        cost = y;
    }
};

vector<edge> G[MAX_V];
ll d[2][MAX_V];
int N, M;

void dijkstra(int s, int ind){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d[ind], d[ind]+N, INF);
    d[ind][s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.sc;
        if(d[ind][v] < p.fs){
            continue;
        }
        for(auto e: G[v]){
            if(d[ind][e.to] > d[ind][v] + e.cost){
                d[ind][e.to] = d[ind][v] + e.cost;
                que.push(P(d[ind][e.to], e.to));
            }
        }
    }
}

ll num[2][101000];
ll count_num(int x, int des){
    if(num[des][x] != -1){
        return num[des][x];
    }

    ll ret = 0;
    for(auto s: G[x]){
        int v = s.to;
        if(d[des][x] == d[des][v] + s.cost){
            ret = add(ret, count_num(v, des));
        }
    }
    num[des][x] = ret;
    return ret;
}


int main(){
    cin >> N >> M;
    int S, T;
    cin >> S >> T;
    S--;
    T--;

    for(int i = 0; i < M; i++){
        int u, v; ll d;
        cin >> u >> v >> d;
        u--; v--;
        G[u].emplace_back(edge(v, d));
        G[v].emplace_back(edge(u, d));
    }

    dijkstra(S, 0);
    dijkstra(T, 1);
    /*for(int i = 0; i < N; i++){
        cout << d[0][i] << endl;
    }*/

    for(int i = 0; i < 2; i++){
        fill(num[i], num[i]+101000, -1);
    }
    num[0][S] = 1; num[1][T] = 1;
    for(int i = 0; i < N; i++){
        count_num(i, 0);
        count_num(i, 1);
    }

    ll total = d[0][T], total_num = num[0][T];
    ll res = 0;
    /*for(int i = 0; i < N; i++){
        cout << num[0][i] << endl;
    }*/
    for(int i = 0; i < N; i++){
        if(d[0][i] * 2 == total){
            ll s_num = num[0][i];
            ll t_num = num[1][i];
            // cout << i << " " << s_num << " " << t_num << endl;
            res = add(res, mul(mul(s_num, t_num), total_num - mul(s_num, t_num)));
        }
        for(auto v: G[i]){
            if(d[0][i] * 2 < total && d[1][v.to] * 2 < total && d[0][i] + d[1][v.to] + v.cost == total){
                ll s_num = num[0][i];
                ll t_num = num[1][v.to];
                res = add(res, mul(mul(s_num, t_num), total_num - mul(s_num, t_num)));
            }
        }
    }

    cout << res << endl;

    return 0;
}
