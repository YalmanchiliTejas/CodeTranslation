#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;

long long mod = 1e9+7;
int N, M, S, T;
vector<pair<int, long long> > adj[100000];
long long d[100000];
bool visited[100000];
long long dp1[100000], dp2[100000];
long long edges[200000][3];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
pair<long long, int> d_and_idx[100000];

int main(){
    cin >> N >> M;
    cin >> S >> T;
    S--;
    T--;
    for(int i = 0; i < M; i++){
        int u, v, d;
        cin >> u >> v >> d;
        adj[u-1].push_back(make_pair(v-1, d));
        adj[v-1].push_back(make_pair(u-1, d));
        edges[i][0] = u-1;
        edges[i][1] = v-1;
        edges[i][2] = d;
    }
    for(int i = 0; i < N; i++){
        if(i != S){
            d[i] = 1e18;
        }
    }


    pq.push(make_pair(0, S));

    while(!pq.empty()){
        int now = pq.top().second;
        long long d_now = pq.top().first;
        pq.pop();
        visited[now] = true;

        if(d[now] < d_now){
            continue;
        }

        for(int i = 0; i < adj[now].size(); i++){
            int next = adj[now][i].first;
            long long cost = adj[now][i].second;
            if(!visited[next] && d[now] + cost < d[next]){
                d[next] = d[now] + cost;
                pq.push(make_pair(d[next], next));
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        //cout << d[i] << endl;
    }
    


    for(int i = 0; i < N; i++){
        d_and_idx[i] = make_pair(d[i], i);
    }
    sort(d_and_idx, d_and_idx + N);
    dp1[d_and_idx[0].second] = 1;
    for(int i = 1; i < N; i++){
        int now = d_and_idx[i].second;
        for(int j = 0; j < adj[now].size(); j++){
            if(d[now] == d[adj[now][j].first] + adj[now][j].second){
                dp1[now] += dp1[adj[now][j].first];
                dp1[now] %= mod;
            }
        }
    }
    dp2[T] = 1;
    for(int i = N - 1; i >= 0; i--){
        int now = d_and_idx[i].second;
        for(int j = 0; j < adj[now].size(); j++){
            if(d[adj[now][j].first] == d[now] + adj[now][j].second){
                dp2[now] += dp2[adj[now][j].first];
                dp2[now] %= mod;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        //cout << dp1[i] << endl;
    }
    /*
    for(int i = 0; i < N; i++){
        cout << dp2[i] << endl;
    }
    */

    long long base = dp1[T] * dp1[T] % mod;
    long long vert = 0;
    for(int i = 0; i < N; i++){
        if(2*d[i] == d[T]){
            vert += dp1[i] * dp1[i] % mod * dp2[i] % mod * dp2[i] % mod;
            vert %= mod;
        }
    }

    long long edge = 0;
    for(int i = 0; i < M; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        long long c = edges[i][2];
        if(d[v] < d[u]){
            int tmp = u;
            u = v;
            v = tmp;
        }
        if(2 * d[u] < d[T] && 2 * d[v] > d[T] && d[u] + c == d[v]){
            edge += dp1[u] * dp1[u] % mod * dp2[v] % mod * dp2[v] % mod;
            edge %= mod;
        }
    }
    //cout << dp1[T] << endl;

    //cout << base << " " << vert << " " << edge << endl;
    cout << (base + 2*mod - vert - edge) % mod << endl;

    return 0;
}
