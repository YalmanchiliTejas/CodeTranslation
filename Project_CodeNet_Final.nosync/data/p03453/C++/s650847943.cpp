#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<ll, ll, ll>;
typedef pair<ll,ll> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

const ll mod = 1000000000 + 7;
const ll INF = 1LL << 61;
ll N, M;
ll S, T;
vector<pii> G[100100];
ll d[2][100010];
ll dp[2][100010];

void dijkstra(ll d[100010], ll s){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(ll i = 0; i < N; i++) d[i] = INF;
    pq.push(pii(0, s));
    d[s] = 0;
    while(pq.size()){
        pii p = pq.top(); pq.pop();
        if(p.first > d[p.second]) continue;
        ll ccost = p.first;
        ll cpos = p.second;
        for(pii np : G[cpos]){
            ll npos = np.first;
            ll ncost = ccost + np.second;
            if(ncost < d[npos]){
                d[npos] = ncost;
                pq.push(pii(ncost, npos));
            }
        }
    }
}

// posから初めてgoalたどり着く経路の個数を計算する
ll path(ll pos, ll goal, ll ccost, ll dp[100010], ll d[100010]){
    if(dp[pos] >= 0) return dp[pos];
    ll res = 0;
    if(pos == goal) res = 1;
    else{
        for(pii p : G[pos]){
            ll npos = p.first;
            ll cost = p.second;
            ll ncost = ccost - cost;
            if(d[npos] == ncost){
                res = (res + path(npos, goal, ncost, dp, d)) % mod;
            }
        }
    }
    return dp[pos] = res;
}

int main(){

    vector<tpl> es;

    cin >> N >> M;
    cin >> S >> T; S--; T--;
    for(ll i = 0; i < M; i++){
        ll f, t, d;
        cin >> f >> t >> d;
        f--; t--;
        G[f].push_back(pii(t, d));
        G[t].push_back(pii(f, d));
        es.push_back(make_tuple(f, t, d));
    }

    dijkstra(d[0], S);
    dijkstra(d[1], T);

    // for(ll i = 0; i < 2; i++){
    //     for(ll j = 0; j < N; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    memset(dp, -1, sizeof(dp));
    
    // dp[0][x]は、xからSまでの経路数
    // dp[1][x]は、xからTまでの経路数
    
    path(T, S, d[0][T], dp[0], d[0]);
    path(S, T, d[1][S], dp[1], d[1]);

    // for(ll i = 0; i < 2; i++){
    //     for(ll j = 0; j < N; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll total = (ll)dp[1][S] * dp[1][S]; // 経路のペアの総数
    total %= mod;


    // 頂点ですれ違う場合
    for(ll i = 0; i < N; i++){
        if(d[0][i] == d[1][i]){
            ll tmp = ((ll)dp[0][i] * dp[1][i]) % mod;
            total -= (tmp * tmp) % mod;
            total += mod;
            total %= mod;
        }
    }

    // 辺上ですれ違う場合
    for(ll i = 0; i < (ll)es.size(); i++){
        ll a = get<0>(es[i]);
        ll b = get<1>(es[i]);
        const ll c = get<2>(es[i]);
        for(int j = 0; j < 2; j++){
            if(d[0][T] == d[0][a] + c + d[1][b]){
                // aに辿り着いた時、すでに、他方が辺にある
                // bに辿り着いた時、すでに、他方が辺にある
                // どちらかを満たしている場合、引く必要あり
                if((d[0][a] >= d[1][b] && d[0][a] < d[1][b] + c) ||
                   (d[1][b] >= d[0][a] && d[1][b] < d[0][a] + c)){
                    ll tmp = ((ll)dp[0][a] * dp[1][b]) % mod;
                    total -= (tmp * tmp) % mod;
                    total += mod;
                    total %= mod;
                }
            }
            swap(a, b);
        }
    }

    cout << total << endl;


    return 0;
}
