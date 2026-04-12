#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(a); ++i)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n == 0) return 1;

    ll res = modpow(x, n/2);
    if(n%2 == 0) return res*res%mod;
    else return res*res%mod*x%mod;
}

ll power(ll x, ll n){
    if(n == 0) return 1;

    ll res = power(x, n/2);
    if(n%2 == 0) return res*res;
    else return res*res*x;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */

ll dp[20000][2][110];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    int n = s.length();
    int D; cin >> D;
    dp[0][0][0] = 1;
    rep(i, n) rep(j, 2) rep(k, D) {
        int lim = j? 9:s[i]-'0';
        rep(d, lim+1){
            (dp[i+1][j || d<lim][(k+d)%D] += dp[i][j][k]) %= mod;
        }
    }

    ll ans = 0;
    rep(j, 2) ans += dp[n][j][0];
    --ans;
    chmod(ans);
    cout << ans << '\n';

	return 0;
}
