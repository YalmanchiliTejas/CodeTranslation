#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rFor(i, a, b) for(int (i)=(int)(a)-1; (i)>=(int)(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<int, lint> pil;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>=0 ? a/b : (a+1)/b-1;
}
template<class T> T div_ceil(T a, T b){
    if(b < 0) a *= -1, b *= -1;
    return a>0 ? (a-1)/b+1 : a/b;
}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod * mod;
constexpr int MAX = 100010;

template<int_fast64_t MOD> struct modint{
    using i64=int_fast64_t;
    i64 a;
    modint(const i64 a_=0): a(a_){
        if(a>MOD) a%=MOD;
        else if(a<0) (a%=MOD)+=MOD;
    }
    modint inv(){
        i64 t=1, n=MOD-2, x=a;
        while(n){
            if(n&1) (t*=x)%=MOD;
            (x*=x)%=MOD;
            n>>=1;
        }
        modint ret(t);
        return ret;
    }
    bool operator==(const modint x) const{return a==x.a;}
    bool operator!=(const modint x) const{return a!=x.a;}
    modint operator+(const modint x) const{
        return modint(*this)+=x;
    }
    modint operator-(const modint x) const{
        return modint(*this)-=x;
    }
    modint operator*(const modint x) const{
        return modint(*this)*=x;
    }
    modint operator/(const modint x) const{
        return modint(*this)/=x;
    }
    modint operator^(const lint x) const{
        return modint(*this)^=x;
    }
    modint &operator+=(const modint &x){
        a+=x.a;
        if(a>=MOD) a-=MOD;
        return *this;
    }
    modint &operator-=(const modint &x){
        a-=x.a;
        if(a<0) a+=MOD;
        return *this;
    }
    modint &operator*=(const modint &x){
        (a*=x.a)%=MOD;
        return *this;
    }
    modint &operator/=(modint x){
        (a*=x.inv().a)%=MOD;
        return *this;
    }
    modint &operator^=(lint n){
        i64 ret=1;
        while(n){
            if(n&1) (ret*=a)%=MOD;
            (a*=a)%=MOD;
            n>>=1;
        }
        a=ret;
        return *this;
    }
    modint operator-() const{
        return modint(0)-*this;
    }
    modint &operator++(){
        return *this+=1;
    }
    modint &operator--(){
        return *this-=1;
    }
    bool operator<(const modint x) const{
        return a<x.a;
    }
};

using mint=modint<1000000007>;

struct edge{
    int to;
    lint cost;
    edge(int to, lint cost): to(to), cost(cost){}
};

int n, m;
vector<edge> G[MAX];

pair<vector<lint>, vector<mint>> dijkstra(int s){
    using pli = pair<lint, int>;
    vector<lint> d(n, INF);
    priority_queue<pli, vector<pli>, greater<>> que;
    que.emplace(0, s);
    d[s] = 0;
    while(!que.empty()){
        lint td;
        int v;
        tie(td, v) = que.top(); que.pop();
        if(td > d[v]) continue;
        for(auto &e: G[v]){
            if(chmin(d[e.to], td + e.cost)) que.emplace(d[e.to], e.to);
        }
    }

    vector<mint> num(n, 0);
    num[s] = 1;
    priority_queue<pli, vector<pli>, greater<>> que2;
    rep(i, n) que2.emplace(d[i], i);
    while(!que2.empty()){
        lint td;
        int v;
        tie(td, v) = que2.top(); que2.pop();
        for(auto &e: G[v])if(d[e.to] == td + e.cost) num[e.to] += num[v];
    }
    return {d, num};
}

int main(){
    int s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    --s; --t;
    rep(_, m){
        int u, v;
        lint d;
        scanf("%d%d%lld", &u, &v, &d);
        --u; --v;
        G[u].emplace_back(v, d);
        G[v].emplace_back(u, d);
    }
    vector<lint> ds, dt;
    vector<mint> cs, ct;
    tie(ds, cs) = dijkstra(s);
    tie(dt, ct) = dijkstra(t);

    mint ans = cs[t] * ct[s];
    rep(v, n)if(ds[v]+dt[v] == ds[t] && ds[v] == dt[v]) ans -= (cs[v]^2) * (ct[v]^2);
    rep(v, n)for(auto &e: G[v]){
        int u = e.to;
        if(ds[v]+e.cost+dt[u] == ds[t] && 2*ds[v] < ds[t] && ds[t] < 2*(ds[v]+e.cost) && 2*dt[u] < dt[s] && dt[s] < 2*(dt[u]+e.cost)){
            ans -= (cs[v]^2) * (ct[u]^2);
        }
    }
    printf("%lld\n", ans.a);
}