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
typedef pair<int, lint> pil;
typedef pair<lint, lint> pll;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return true;} return false;}
template<class T> bool chmin(T &a, const T &b){if(a>b){a=b; return true;} return false;}
template<class T> T div_floor(const T a, const T b){return a>=0 ? a/b : (a+1)/b-1;}
template<class T> T div_ceil(const T a, const T b){return a>=0 ? (a-1)/b+1 : a/b;}

constexpr lint mod = 1e9+7;
constexpr lint INF = mod*mod;
constexpr int MAX = 100010;

int main(){
    string s;
    int K;
    cin >> s >> K;
    int n = s.size();
    lint dp[n+1][2][K+1];
    rep(i, n+1)rep(j, 2)rep(k, K+1) dp[i][j][k] = 0;
    dp[0][0][0] = 1;
    rep(i, n)rep(j, 2)rep(k, K+1){
        int x = j ? 9 : s[i]-'0';
        rep(d, x+1){
            if(d == 0) dp[i+1][j || d < x][k] += dp[i][j][k];
            else if(k < K) dp[i+1][j || d < x][k+1] += dp[i][j][k];
        }
    }
    lint ans = 0;
    rep(j, 2) ans += dp[n][j][K];
    printf("%lld\n", ans);
}