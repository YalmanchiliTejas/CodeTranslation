#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<long long Mod>
struct mint{
    long long x;
    mint(long long x=0) :x((x% Mod+Mod)%Mod){}

    mint operator-() const { return mint(-x); }

    mint& operator+=(const mint a) {
        if((x += a.x) >= Mod) x -= Mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if((x += Mod-a.x) >= Mod) x -= Mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= Mod;
        return *this;
    }

    mint operator^(long long t) const {
        mint ret(1);
        mint a = *this;
        while(t){
            if(t&1){
                ret *= a;
            }
            a *= a;
            t >>= 1;
        }
        return ret;
    }
    mint inv() const { return *this ^ (Mod-2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }

    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint operator/(const mint a) const { return mint(*this) /= a; }

    friend istream& operator>>(istream& is, mint& a) { return is >> a.x; }
    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }
};

int N, M;
int A[200000], B[200000], C[200000];
vector<pair<int, int>> e[100000];

int S, T;
ll costS[100000], costT[100000];

void dijkstra(int S, ll cost[]){
    rep(i, N) cost[i] = 1e18L;
    cost[S] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push({ 0,S });
    while(!pq.empty()){
        int n = pq.top().second;
        pq.pop();
        rep(i, e[n].size()){
            if(cost[e[n][i].first] > cost[n] + e[n][i].second){
                cost[e[n][i].first] = cost[n] + e[n][i].second;
                pq.push({ -cost[e[n][i].first], e[n][i].first });
            }
        }
    }
}

mint<MOD> wayS[100000], wayT[100000];

void dp(int S, ll cost[], mint<MOD> way[]){
    priority_queue<pair<ll,int>> pq;
    rep(i, N){
        pq.push({ -cost[i], i });
    }
    way[S] = 1;
    rep(i, N){
        int n = pq.top().second;
        pq.pop();
        rep(j, e[n].size()){
            if(cost[e[n][j].first] + e[n][j].second == cost[n]){
                way[n] += way[e[n][j].first];
            }
        }
    }
}

signed main(){
    cin >> N >> M;
    cin >> S >> T;
    S--; T--;
    rep(i, M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        e[A[i]].pb({ B[i], C[i] });
        e[B[i]].pb({ A[i], C[i] });
    }

    dijkstra(S, costS);
    dijkstra(T, costT);
    ll t = costS[T];

    dp(S, costS, wayS);
    dp(T, costT, wayT);

    mint<MOD> ans = wayS[T] * wayT[S];

    rep(i, M){
        int a = A[i];
        int b = B[i];
        if(costS[a] > costS[b]) swap(a, b);
        if(2*costS[a] < t && t < 2*costS[b] && 2*costT[b] < t && t < 2*costT[a]
            && costS[a] + C[i] == costS[b] && costT[b] + C[i] == costT[a]
            && costS[a] + C[i] + costT[b] == t){
            ans -= (wayS[a] * wayT[b]) ^ 2;
        }
    }

    rep(i, N){
        if(2*costS[i] == t && 2*costT[i] == t){
            ans -= (wayS[i] * wayT[i]) ^ 2;
        }
    }

    cout << ans << endl;
}