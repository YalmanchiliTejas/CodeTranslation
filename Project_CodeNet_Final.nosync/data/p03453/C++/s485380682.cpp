#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

constexpr ll mod = 1e9+7;
struct mint {
    ll x;
    mint(ll x=0):x((x%mod+mod)%mod){}
    
    friend ostream &operator<<(ostream& os,const mint& a){
        return os << a.x;
    }

    friend istream &operator>>(istream& is,mint& a){
        ll t;
        is >> t;
        a = mint(t);
        return (is);
    }

    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(mod-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin >> N >> M;
    int S,T;
    cin >> S >> T;
    S--; T--;
    struct edge{
        int from,to;
        ll d;
    };
    vec<edge> E;
    vvec<edge> g(N);
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({a,b,c});
        g[b].push_back({b,a,c});
        E.push_back({a,b,c});
        E.push_back({b,a,c});
    }
    ll inf = 1e18;
    vec<ll> distS(N,inf),distT(N,inf);
    vec<mint> dpS(N,0),dpT(N,0);

    using P = Pa<ll,int>;
    auto dijkstra = [&](int s,vec<ll>& dist,vec<mint>& dp){
        priority_queue<P,vec<P>,greater<P>> Q;
        Q.push({0,s});
        dist[s] = 0;
        dp[s] = 1;
        while(!Q.empty()){
            auto p = Q.top(); Q.pop();
            ll d = p.first;
            int cur = p.second;
            if(dist[cur]<d) continue;
            for(auto& e:g[cur]){
                ll nd = d+e.d;
                if(dist[e.to]>nd){
                    dist[e.to] = nd;
                    dp[e.to] = dp[cur];
                    Q.push({nd,e.to});
                }else if(dist[e.to]==nd){
                    dp[e.to] += dp[cur];
                }
            }
        }
    };
    dijkstra(S,distS,dpS),dijkstra(T,distT,dpT);
    mint ans = dpS[T]*dpT[S];
    set<int> s;
    for(auto& e:E){
        int a = e.from,b = e.to;
        if(distS[a]+e.d+distT[b]!=distS[T]) continue;
        if(distT[b]+e.d+distS[a]!=distT[S]) continue;
//           cerr << a << " " << b << "\n";
//           cerr << distS[a] << " " << e.d << " " << distT[b] << "\n";
        double sl = distS[a]+0.1,sr = distS[b]-0.1;
        double tl = distT[b]+0.1,tr = distT[a]-0.1;
        s.insert(a);
        s.insert(b);
        if(max(sl,tl)<=min(sr,tr)){
            ans -= dpS[a]*dpS[a]*dpT[b]*dpT[b];
        }
    }
//    cerr << ans << "\n";
    for(int i=0;i<N;i++) if(s.count(i) && distS[i]==distT[i]) ans -= dpS[i]*dpS[i]*dpT[i]*dpT[i];
    cout << ans << "\n";
}