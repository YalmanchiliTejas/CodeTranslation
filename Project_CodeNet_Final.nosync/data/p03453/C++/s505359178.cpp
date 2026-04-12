#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <utility>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <cstdio>
#include <map>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define _upgrade ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define all(x) (x).begin(), (x).end()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define pb push_back

template<class T1, class T2> void chmin(T1 &a, T2 b){if(a>b)a=b;}
template<class T1, class T2> void chmax(T1 &a, T2 b){if(a<b)a=b;}

//ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
//ll lcm(ll x, ll y) {return x / gcd(x, y) * y;}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

const ll INF = 1LL << 60;
const long double PI = 3.14159265358979323846;


// ****************************************CODE***************************************//

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



    //覚えておかないといけないことがあるよね。
    //
    //まずqueの入れ方で,firstに最短距離を入れて、secondにどこの地点にいるのかってことを入れるんだよね。
    //そして最初に作る隣接リストのグラフでは、行の先頭をfrom, 一個目を行き先、二個目をその辺のコストを入れるんだよね。
    //それでおっけいのはず


    int N, M, S, T;
    vector<pair<int, ll>> E[101010];
    //------------------------------------------------------
    template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

    int vis[101010];

    void dij(int s, vector<ll> &dis, vector<mint> &pat) {
        //初期化だにょーん
        rep(i,N) dis[i] = INF;
        rep(i,N) pat[i] = 0;
        rep(i,N) vis[i] = 0;

        min_priority_queue<pair<ll, int>> que;

        dis[s] = 0;
        pat[s] = 1;
        que.push({0, s});

        while(!que.empty()){
            auto q = que.top(); que.pop();

            int cu = q.second; //どこの地点にいるかだよね
            ll cst = q.first;  //最短距離だよね

            if(vis[cu]) continue; //もしその地点訪れてたら抜けるよね
            vis[cu] = 1;          //訪れたこと記録するよね

            for(auto p : E[cu]){  //p.first = どこに p.second == コスト
                if(!vis[p.first]){ 
                    if(dis[cu] + p.second < dis[p.first]){
                        dis[p.first] = dis[cu] + p.second;
                        pat[p.first] = pat[cu];  //行ける場所に前の頂点の経路を代入するよね。だって前の経路の続きだからその経路数を引き継ぐよね
                        que.push({ dis[p.first], p.first });
                    }
                    else if(dis[cu] + p.second == dis[p.first]){ 
                        pat[p.first] += pat[cu]; //もし行き先と最短経路の大きさが等しかったら新しい経路ができたってことだからそこに今までの経路を足す。
                    }
                }
            }
        }
    }

//---------------------------------------------------------------

int main(){
    cin >> N >> M >> S >> T;
    S--;
    T--;
    rep(i,M){
        int a, b, c;  cin >> a >> b >> c;
        a--; b--;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }

    vector<ll> disS(N), disT(N);
    vector<mint> patS(N), patT(N);
    dij(S, disS, patS);
    dij(T, disT, patT);

    ll len = disS[T];

    mint ans = patS[T] * patS[T];

    rep(i,N){
        if(disS[i] + disT[i] == len and disS[i] * 2 == len){
            ans -= patS[i] * patT[i] * patS[i] * patT[i];
        }
    } 

    rep(i,N){
        for(auto p : E[i]){
            int j = p.first;
            ll c = p.second;

            if(disS[i] + c + disT[j] == len){
                if(disS[i] * 2 < len and disT[j] * 2 < len){
                    ans -= patS[i] * patT[j] * patS[i] * patT[j];
                }
            }
        }
    }

    cout << ans << endl;
}
