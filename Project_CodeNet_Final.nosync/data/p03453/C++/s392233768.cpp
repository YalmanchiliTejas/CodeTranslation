#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
const int inf = 1 << 30;
const ll linf = 1e18;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

template<long long mod>
struct modint{
    long long num;

    constexpr modint(long long x = 0) : num((x + mod) % mod) {}

    constexpr modint &operator += (const modint& rhs){
        num = (num + rhs.num) % mod;
        return *this;
    }
    constexpr modint &operator -= (const modint& rhs){
        num  -= rhs.num;
        while(num < 0) num += mod;
        num %= mod;
        return *this;
    }
    constexpr modint &operator *= (const modint& rhs){
        num = num * rhs.num % mod;
        return *this;
    }
    constexpr modint &operator /= (modint rhs){
        int exp = mod - 2;
        while(exp > 0){
            if(exp % 2){
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }

    constexpr modint operator ++ (){
        ++num;
        return *this;
    }
    constexpr modint operator ++ (int n){
        modint tmp = *this;
        ++(*this);
        return tmp;
    }
    constexpr modint operator -- (){
        --num;
        return *this;
    }
    constexpr modint operator -- (int n){
        const modint tmp = *this;
        --(*this);
        return tmp;
    }

    void modpow(ll y){
        modint tmp = (*this);
        (*this) = 1;
        while(y > 0){
            if(y % 2){
                (*this) *= tmp;
            }
            tmp *= tmp;
            y /= 2;
        }
    }

    constexpr modint operator + (const modint& rhs) const {
        return modint(*this) += rhs;
    }
    constexpr modint operator - (const modint& rhs) const {
        return modint(*this) -= rhs;
    }
    constexpr modint operator * (const modint& rhs) const {
        return modint(*this) *= rhs;
    }
    constexpr modint operator / (const modint& rhs) const {
        return modint(*this) /= rhs;
    }

    
    friend ostream &operator << (ostream& lhs, const modint& rhs){
        return lhs << rhs.num;
    }

    friend istream &operator >> (istream& lhs, modint& rhs){
        long long tmp;
        lhs >> rhs.num;
        return lhs;
    }
};

#define mint modint<1000000007>

struct edge{
    int to;
    ll cost;
};

struct node{
    int n;
    ll cost;
    bool operator < (const node& n) const {
        return cost < n.cost;
    }
    
    bool operator > (const node& n) const {
        return cost > n.cost;
    }
};

int N, M, S, T;
ll cost1[100010], cost2[100010];
mint cnt1[100010], cnt2[100010];
bool used[100010];
vector<edge> G[100010];

void add_edge(int a, int b, ll c){
    G[a].push_back(edge{b, c});
    G[b].push_back(edge{a, c});
}

void dijkstra(int s, ll* cost, mint* cnt){
    for(int i = 1; i <= N; i++) cost[i] = linf;
    for(int i = 1; i <= N; i++) used[i] = false;
    
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push(node{s, 0});
    cost[s] = 0;

    while(!pq.empty()){
        node n = pq.top();
        pq.pop();

        if(cost[n.n] < n.cost) continue;

        for(auto& e : G[n.n]){
            if(cost[e.to] > e.cost + n.cost){
                cost[e.to] = e.cost + n.cost;
                pq.push(node{e.to, cost[e.to]});
            }
        }
    }

    pq.push({s, 0});
    used[s] = true;
    cnt[s] = 1;

    while(!pq.empty()){
        node n = pq.top();
        pq.pop();

        for(auto& e : G[n.n]){
            if(cost[e.to] == e.cost + n.cost){
                cnt[e.to] += cnt[n.n];
                if(!used[e.to]){
                    used[e.to] = true;
                    pq.push(node{e.to, cost[e.to]});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> S >> T;
    for(int i = 0; i < M; i++){
        int U, V, D;
        cin >> U >> V >> D;
        add_edge(U, V, D);
    }
    dijkstra(S, cost1, cnt1);
    dijkstra(T, cost2, cnt2);
    
    mint ans = cnt1[T] * cnt2[S];
    for(int i = 1; i <= N; i++){
        if(cost1[i] * 2 == cost1[T]){
            ans -= cnt1[i] * cnt1[i] * cnt2[i] * cnt2[i];
        }else if(cost1[i] * 2 < cost1[T]){
            for(auto u : G[i]){
                if(cost1[u.to] * 2 > cost1[T] && cost1[i] + u.cost == cost1[u.to] && cost1[u.to] + cost2[u.to] == cost1[T]){
                    ans -= cnt1[i] * cnt1[i] * cnt2[u.to] * cnt2[u.to];
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}