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
constexpr int MAX = 200010;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int p[1<<(n+1)];
    rep(i, 1<<n){
        scanf("%d", &p[i]);
        p[i+(1<<n)] = p[i];
    }

    int dp[1<<(n+1)][n+1];
    rep(i, 1<<n) dp[i][0] = dp[i+(1<<n)][0] = p[i];
    For(j, 1, n+1)rep(i, 1<<n){
        int a = dp[i][j-1], b = dp[i+(1<<j-1)][j-1];
        if(a < b) swap(a, b);
        dp[i][j] = dp[i+(1<<n)][j] = (s[a-b-1] == '1' ? a : b);
    }
    rep(i, 1<<n) printf("%d\n", dp[i][n]);
}
