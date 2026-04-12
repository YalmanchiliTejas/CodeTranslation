#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;

//typedef tuple<int,int,int> T;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2147483600;//10^9
ll MOD  = 1000000007;
int N,M;
int S,T;
struct edge{ll to, cost;};
vector<edge> es[100010];


ll dS[100010];
ll numS[100010];
void dijkstraS(){
    for(int i = 0; i < 100010; i++) dS[i] = INFL;
    dS[S] = 0;
    numS[S] = 1;
    priority_queue<P, vector<P>, greater<P>> pque;
    pque.push({0, S});
    
    while(!pque.empty()){
        ll c = pque.top().first;
        int v = pque.top().second;
        pque.pop();
        if(dS[v] < c) continue;
        for(int i = 0; i < es[v].size(); i++){
            edge e = es[v][i];
            if(dS[e.to] > dS[v] + e.cost){
                dS[e.to] = dS[v] + e.cost;
                numS[e.to] = numS[v];
                pque.push({dS[e.to], e.to});
            }else if(dS[e.to] == dS[v] + e.cost){
                numS[e.to] += numS[v];
                numS[e.to] %= MOD;
            }
        }
    }
}

ll dT[100010];
ll numT[100010];

void dijkstraT(){
    for(int i = 0; i < 100010; i++) dT[i] = INFL;
    
    dT[T] = 0;
    numT[T] = 1;
    priority_queue<P, vector<P>, greater<P>> pque;
    pque.push({0, T});
    
    while(!pque.empty()){
        ll c = pque.top().first;
        int v = pque.top().second;
        pque.pop();
        if(dT[v] < c)continue;
        
        for(int i = 0; i < es[v].size(); i++){
            edge e = es[v][i];
            if(dT[e.to] > dT[v] + e.cost){
                dT[e.to] = dT[v] + e.cost;
                numT[e.to] = numT[v];
                pque.push({dT[e.to], e.to});
            }else if(dT[e.to] == dT[v] + e.cost){
                numT[e.to] += numT[v];
                numT[e.to] %= MOD;
            }
        }
    }
}

int main(void){
    
    cin >> N >> M;
    cin >> S >> T;
    S--;
    T--;
    for(int i = 0; i < M; i++){
        ll u,v;
        ll d;
        cin >> u >> v >> d;
        u--;
        v--;
        d *= 2;
        es[u].push_back({v, d});
        es[v].push_back({u, d});
        
    }    
    
    dijkstraS();
    dijkstraT();
    ll all = numS[T] * numT[S];
    all %= MOD;
    ll half = dS[T] / 2;
    
    ll same = 0;
    for(int i = 0; i < N; i++){
        if(dS[i] == dS[i] && dS[i] == half){
            ll dsame = numS[i] * numT[i] % MOD * numS[i] % MOD * numT[i] % MOD;
            same += dsame;
            same %= MOD;
        }
    }
    
    ll through = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < es[i].size(); j++){
            int a = i;
            int b = es[i][j].to;
            ll fromSa = dS[a];
            ll fromSb = dS[b];
            ll fromTa = dT[a];
            ll fromTb = dT[b];
            if(fromSa + fromTb + es[i][j].cost == 2 * half){
                if(fromSa < fromSb && fromTb < fromTa){
                    if(fromSa < half && half < fromSb){
                        ll dthrough = numS[a] * numT[b] % MOD * numS[a] % MOD * numT[b] % MOD;
                        through += dthrough;
                        through %= MOD;
                    }
                }
            }
        }
    }
    cout << (((all - same - through) % MOD) + MOD) % MOD << endl;
}
