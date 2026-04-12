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

using pip = pair<int, pii>;

void update(map<pip, lint> &dp, int i, int j, int k, lint x){
    if(dp.find({i, {j, k}}) != dp.end()) chmax(dp[{i, {j, k}}], x);
    else dp[{i, {j, k}}] = x;
}

lint get_val(map<pip, lint> &dp, int i, int j, int k){
    return dp.find({i, {j, k}}) != dp.end() ? dp[{i, {j, k}}] : -INF;
}

int main(){
    int n;
    scanf("%d", &n);
    lint a[n];
    rep(i, n) scanf("%lld", &a[i]);

    map<pip, lint> dp;
    dp[{0, {0, 0}}] = 0;
    rep(i, n)For(j, (i-1)/2, (i-1)/2+2)rep(k, 2){
        lint tmp = get_val(dp, i, j, k);
        update(dp, i+1, j, 0, tmp);
        if(k == 0) update(dp, i+1, j+1, 1, tmp + a[i]);
    }

    lint ans = -INF;
    rep(k, 2) chmax(ans, get_val(dp, n, n/2, k));
    printf("%lld\n", ans);
}