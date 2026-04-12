#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;constexpr ll INF=1LL<<60,MOD=1e9+7;//998244353;
void solve();int main(){cin.tie(nullptr);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();return 0;}
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(int i=0;i<(int)n;++i)
#define _rep1(i,k,n) for(int i=k;i<(int)n;++i)
#define _rep2(i,k,n,d) for(int i=k;d>0?i<(int)n:i>(int)n;i+=d)
#ifdef __LOCAL
#include "ostreams.h"
#endif
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
template<class T> vector<T> make_vector(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_vector(size_t a,Ts... ts){return vector<decltype(make_vector(ts...))>(a,make_vector(ts...));}
void print(){cerr<<endl;} template<class T,class... Ts> void print(const T& a,const Ts&... ts){cerr<<a<<' ';print(ts...);}

void solve(){
    ll n; cin >> n;
    vector<ll> A(3 * n);
    rep(i, 3 * n) cin >> A[i], A[i]--;

    // n : wild card
    auto dp = make_vector(n + 1, n + 1, -INF);
    auto update = [&](ll i, ll j, ll v){
        chmax(dp[i][j], v);
        chmax(dp[j][i], v);
        chmax(dp[i][n], v);
        chmax(dp[n][i], v);
        chmax(dp[n][j], v);
        chmax(dp[j][n], v);
        chmax(dp[n][n], v);
    };

    // initialize
    update(A[0], A[1], 0);

    // iterate
    ll base = 0;
    rep(i, n - 1){
        ll x = A[3 * i + 2], y = A[3 * i + 3], z = A[3 * i + 4];
        if(x == y and y == z){
            base++;
            continue;
        }
        vector<tuple<ll, ll, ll>> update_queue;
        rep(_, 3){
            // 手持ちから1枚使う
            rep(a, n){
                update_queue.emplace_back(a, x, dp[a][n]);
                if(y == z){
                    update_queue.emplace_back(a, x, dp[a][y] + 1);
                }
            }
            // 手持ちから0枚使う
            update_queue.emplace_back(x, y, dp[n][n]);
            update_queue.emplace_back(x, y, dp[z][z] + 1);
            swap(x, y); swap(y, z);
        }
        // update
        for(auto& [i, j, v] : update_queue){
            update(i, j, v);
        }
    }

    ll ans = max(dp[n][n], dp[A[3 * n - 1]][A[3 * n - 1]] + 1) + base;
    cout << ans << endl;
}