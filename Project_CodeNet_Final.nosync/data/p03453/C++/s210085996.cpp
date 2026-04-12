//https://www.hamayanhamayan.com/entry/2018/01/28/234531
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
const int mod = 1000000007;
struct mint
{
    ll x;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    mint inv() const
    {
        return pow(mod - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
};

int N, M, S, T;
vector<pair<int, ll>> E[101010];
//---------------------------------------------------------------------------------------------------
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int vis[101010];
void dij(int s, vector<ll> &dis, vector<mint> &pat) {
    rep(i, 0, N) dis[i] = infl;
    rep(i, 0, N) pat[i] = 0;
    rep(i, 0, N) vis[i] = 0;

    min_priority_queue<pair<ll, int>> que;

    dis[s] = 0;
    pat[s] = 1;
    que.push({ 0, s });

    while (!que.empty()) {
        auto q = que.top(); que.pop();

        int cu = q.second;
        ll cst = q.first;

        if (vis[cu]) continue;
        vis[cu] = 1;

        fore(p, E[cu]) if(!vis[p.first]) {
            if (dis[cu] + p.second < dis[p.first]) {
                dis[p.first] = dis[cu] + p.second;
                pat[p.first] = pat[cu];
                que.push({ dis[p.first], p.first });
            }
            else if (dis[cu] + p.second == dis[p.first]) {
                pat[p.first] += pat[cu];
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> M >> S >> T;
    S--;
    T--;
    rep(i, 0, M) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        E[a].push_back({ b, c });
        E[b].push_back({ a, c });
    }
    vector<ll> disS(N), disT(N);
    vector<mint> patS(N), patT(N);
    dij(S, disS, patS);
    dij(T, disT, patT);

    ll len = disS[T];

    mint ans = patS[T] * patS[T];

    rep(i, 0, N) if (disS[i] + disT[i] == len and disS[i] * 2 == len) {
        ans -= patS[i] * patT[i] * patS[i] * patT[i];
    }

    
    rep(i, 0, N) fore(p, E[i]) {
        int j = p.first;
        ll c = p.second;

        if (disS[i] + c + disT[j] == len) {
            //printf("[%d %d]\n", i + 1, j + 1);
            if (disS[i] * 2 < len and disT[j] * 2 < len) {
                ans -= patS[i] * patT[j] * patS[i] * patT[j];
            }
        }
    }

    cout << ans.x << endl;
}
