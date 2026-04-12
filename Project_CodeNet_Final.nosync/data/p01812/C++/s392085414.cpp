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

int main(){
    int n, m, K;
    scanf("%d%d%d", &n, &m, &K);
    int dark[n], v[n][K], idx[m], rev[n];
    memset(dark, 0, sizeof(dark));
    rep(i, m){
        scanf("%d", &idx[i]);
        --idx[i];
        dark[idx[i]] = 1;
        rev[idx[i]] = i;
    }
    rep(i, n)rep(j, K){
        scanf("%d", &v[i][j]);
        --v[i][j];
    }

    int dist[1<<m];
    fill(dist, dist+(1<<m), mod);
    queue<pii> que;
    que.emplace((1<<m)-1, 0);
    dist[(1<<m)-1] = 0;
    while(!que.empty()){
        int S, d;
        tie(S, d) = que.front();
        que.pop();
        rep(j, K){
            int T = 0;
            rep(i, m)if(S>>i & 1){
                int to = v[idx[i]][j];
                if(dark[to]) T |= 1 << rev[to];
            }
            if(chmin(dist[T], d + 1)){
                if(T == 0){
                    printf("%d\n", d + 1);
                    return 0;
                }
                que.emplace(T, d + 1);
            }
        }
    }
}
