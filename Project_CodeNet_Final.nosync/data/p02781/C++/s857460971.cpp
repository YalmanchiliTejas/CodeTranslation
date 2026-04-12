#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
template<class T> using vc = vector<T>;
template<class T> using vvc = vector<vector<T>>;

const ll MOD = 1e9 + 7;
const ll INF = 1e14;
const ld EPS = 1e-11;
const ld PI = acos(-1.0L);
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define repr(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (ll i = (l); i < (r); i++)
#define reper(i, l, r) for (ll i = (r)-1; i >= (l); i--)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void init() {cin.tie(0);ios::sync_with_stdio(false);cout << fixed << setprecision(15);}
//--------------------------------------------------------------------------------//

int main() {
    init();
    string s;
    ll K;
    cin >> s >> K;

    ll ans = 0;
    ll digit = s.size();
    
    vl P(digit);
    rep(i,digit){
        P[i] = s[i] - '0';
    }
    // digit, K count, bound
    vc<vvc<ll>> dp(digit+1, vvc<ll>(K+1, vc<ll>(2, 0)));
    dp[0][0][1] = 1;
    rep(d,digit){
        rep(k,K){
            if(P[d]==0){
                dp[d + 1][k][0] += dp[d][k][0];
                dp[d + 1][k + 1][0] += dp[d][k][0] * 9;

                dp[d + 1][k][1] = dp[d][k][1];

            }
            else{
                dp[d + 1][k][0] += dp[d][k][1] + dp[d][k][0];
                dp[d + 1][k + 1][0] += dp[d][k][1] * max(0ll, P[d] - 1);
                dp[d + 1][k + 1][0] += dp[d][k][0] * 9;

                dp[d + 1][k+1][1] = dp[d][k][1];
                
            }
            
            
        }
        dp[d + 1][K][0] += dp[d][K][0];
        dp[d + 1][K][1] += dp[d][K][1];
    }
    /*
    rep(i,digit+1){
        rep(j,2){
            rep(k,K+1){
                cout << dp[i][k][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    */
    cout << dp[digit][K][0] + dp[digit][K][1] << endl;
}