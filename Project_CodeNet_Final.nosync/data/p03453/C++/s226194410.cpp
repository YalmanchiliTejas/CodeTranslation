#include <bits/stdc++.h>
using namespace std;

template <uint32_t mod>
class modint{
    uint64_t value;
public:
    constexpr modint(const int64_t x=0) noexcept: value(x % mod + (x < 0 ? mod : 0)){ }
    constexpr explicit operator uint64_t() const noexcept{ return value; }
    constexpr modint inverse() const noexcept{ return pow(*this, mod-2); }
    constexpr bool operator==(const modint &rhs) const noexcept{ return value == rhs.value; }
    constexpr bool operator!=(const modint &rhs) const noexcept{ return value != rhs.value; }
    constexpr modint operator+() const noexcept{ return modint(*this); }
    constexpr modint operator-() const noexcept{ return modint(mod - value); }
    constexpr modint operator+(const modint &rhs) const noexcept{ return modint(*this) += rhs; }
    constexpr modint operator-(const modint &rhs) const noexcept{ return modint(*this) -= rhs; }
    constexpr modint operator*(const modint &rhs) const noexcept{ return modint(*this) *= rhs; }
    constexpr modint operator/(const modint &rhs) const noexcept{ return modint(*this) /= rhs; }
    constexpr modint &operator+=(const modint &rhs) noexcept{
        if((value += rhs.value) >= mod) value -= mod;
        return *this;
    }
    constexpr modint &operator-=(const modint &rhs) noexcept{ return *this += mod - rhs.value; }
    constexpr modint &operator*=(const modint &rhs) noexcept{
        if((value *= rhs.value) >= mod) value %= mod;
        return *this;
    }
    constexpr modint &operator/=(const modint &rhs) noexcept{ return *this *= rhs.inverse(); }
    constexpr modint operator++(int) noexcept{
        modint ret(*this);
        if((++value) >= mod) value -= mod;
        return ret;
    }
    constexpr modint operator--(int) noexcept{
        modint ret(*this);
        if((value += mod - 1) >= mod) value -= mod;
        return ret;
    }
    constexpr modint &operator++() noexcept{ return *this += 1; }
    constexpr modint &operator--() noexcept{ return *this -= 1; }
    friend std::ostream &operator<<(std::ostream &os, const modint<mod> &x){ return os << x.value; }
    friend std::istream &operator>>(std::istream &is, modint<mod> &x){
        int64_t i;
        is >> i;
        x = modint<mod>(i);
        return is;
    }
    friend constexpr modint<mod> pow(const modint<mod> &x, uint64_t y){
        modint<mod> ret{1}, m{x};
        while(y > 0){
            if(y & 1) ret *= m;
            m *= m;
            y >>= 1;
        }
        return ret;
    }
};
constexpr int64_t mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, m, s, t;
    static vector<pair<int, int64_t>> edges[100001];
    cin >> n >> m;
    cin >> s >> t;
    for(int i=0;i<m;++i){
        int u, v;
        int64_t d;
        cin >> u >> v >> d;
        edges[u].emplace_back(v, d*2);
        edges[v].emplace_back(u, d*2);
    }

    static int64_t dist[100001];
    static vector<int> pv[100001], nx[100001];
    priority_queue<pair<int64_t, int>> q;

    for(int i=1;i<=n;++i) dist[i] = INT64_MAX;
    dist[s] = 0;
    q.emplace(0, s);
    while(!q.empty()){
        int64_t c;
        int v;
        tie(c, v) = q.top();
        q.pop();
        if(dist[v] < -c) continue;
        if(-c > dist[t]) break;
        for(auto e: edges[v]){
            int u;
            int64_t w;
            tie(u, w) = e;
            if(w-c < dist[u]){
                dist[u] = w-c;
                q.emplace(c-w, u);
                pv[u].clear();
                pv[u].push_back(v);
            }else if(w-c == dist[u]) pv[u].push_back(v);
        }
    }

    set<pair<int, int>> half;
    static modint<mod> cnt[2][100001];
    cnt[0][s] = 1; cnt[1][t] = 1;
    priority_queue<pair<int64_t, int>> qq;
    qq.emplace(dist[t], t);
    while(!qq.empty()){
        int64_t c;
        int v;
        tie(c, v) = qq.top();
        qq.pop();
        for(int u: pv[v]){
            nx[u].push_back(v);
            if(cnt[1][u] == 0) qq.emplace(dist[u], u);
            cnt[1][u] += cnt[1][v];
            if(dist[u] == dist[t]/2) half.emplace(u, u);
            else if(dist[v] > dist[t]/2 && dist[u] < dist[t]/2) half.emplace(u, v);
        }
    }
    qq.emplace(0, s);
    while(!qq.empty()){
        int64_t c;
        int v;
        tie(c, v) = qq.top();
        qq.pop();
        for(int u: nx[v]){
            if(cnt[0][u] == 0) qq.emplace(-dist[u], u);
            cnt[0][u] += cnt[0][v];
        }
    }
    modint<mod> ans = 0;
    for(auto h: half){
        ans += cnt[0][h.first] * cnt[0][h.first] * cnt[1][h.second] * cnt[1][h.second];
    }

    cout << cnt[0][t]*cnt[1][s] - ans << endl;
    return 0;
}