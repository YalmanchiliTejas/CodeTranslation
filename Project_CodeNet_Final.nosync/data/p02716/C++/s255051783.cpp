#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; (i) < (n); (i)++)
#define INF 5000000000000000
using namespace std;

struct Edge{
    int to;
    long weight;
    Edge(int t, long w) : to(t), weight(w) {}
};

long modpow(long a, long n, long mod) {
    long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long modinv(long a, long mod) {
    return modpow(a, mod - 2, mod);
}

struct compare1 { 
    bool operator()(const pair<long, long>& value,  
                                const long& key) 
    { 
        return (value.first < key); 
    } 
    bool operator()(const long& key,  
                    const pair<long, long>& value) 
    { 
        return (key < value.first); 
    } 
};

struct UnionFind {
    vector<int> par;
    vector<int> rank;

    UnionFind(int n = 1){
        init(n);
    }

    void init(int n = 1){
        par.resize(n);
        rank.resize(n);
        REP(i, n) par[i] = i, rank[i] = 0; 
    }

    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        return true;
    }
};

template<class Abel> struct weightedUnionFind{
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;

    weightedUnionFind(int n = 1, Abel SUM_UNITY = 0){
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0){
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        REP(i, n) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY; 
    }

    int root(int x){
        if(par[x] == x) return x;
        else{
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x){
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w){
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y), w = -w;
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y){
        return weight(y) - weight(x);
    }
};

using Graph = vector<vector<int>>;
using P = pair<int, int>;

/*
void dijkstra(int s, int V, Graph &G, long* d){
    priority_queue<P, vector<P>, greater<P>> pque;
    fill(d, d + V, INF);
    d[s] = 0;
    pque.push(P(0, s));

    while(!pque.empty()){
        P p = pque.top(); pque.pop();
        int now = p.second;
        if(d[now] < p.first) continue;
        REP(i, G[now].size()){
            Edge e = G[now][i];
            if(d[e.to] > d[now] + e.weight){
                d[e.to] = d[now] + e.weight;
                pque.push(P(d[e.to], e.to));
            }
        }
    }
}
*/

int GCD(int a, int b){
    if(b == 0) return a; 
    if(a < b) return GCD(b, a);
    else return GCD(b, a%b);
}

int main()
{
    int N; cin >> N;
    long A[200005];
    REP(i, N) cin >> A[i];
    long sumg[200005], ans[200005], dp[200005];
    if(N%2 == 0){
        ans[0] = max(A[0], A[1]);
        long temp = A[0];
        for(int i=1; i<=N/2-1; i++){
            temp += A[2*i];
            ans[i] = max(ans[i-1] + A[2*i+1], temp);
        }
        cout << ans[N/2-1] << endl;
    }else{
        ans[0] = max(A[0], A[1]);
        long temp = A[0];
        for(int i=1; i<=(N-3)/2; i++){
            temp += A[2*i];
            ans[i] = max(ans[i-1] + A[2*i+1], temp);
        }
        //cout << ans[(N-3)/2] << endl;
        dp[0] = 0;
        for(int i=1; i<= (N-1)/2; i++){
            dp[i] = max(A[2*i] + dp[i-1], ans[i-1]);
        }
        cout << dp[(N-1)/2] << endl;
    }
    return 0;
}

