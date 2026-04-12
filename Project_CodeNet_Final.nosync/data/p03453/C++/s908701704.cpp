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
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
typedef ModInt<1000000007> mint;
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/




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

    cout << ans << endl;
}
