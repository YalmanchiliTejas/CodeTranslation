#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second
 
// rep(i, 0, sz(v)) cout << v[i] << " \n"[i==sz(v)-1];
 
////////////////////////////////////////////////////////
string s;
ll k;

ll dp[105][2][5]; // 桁数、未満フラグ、条件

int main() {
    cin >> s >> k;
    ll n = sz(s);

    dp[0][0][0] = 1;

    rep(i, 0, n){
        rep(sm, 0, 2){
            rep(j, 0, k+1){
                ll c_ = s[i] - '0'; // 現在見ている位の値
                rep(c, 0, 10){
                    if(sm) dp[i+1][1][(c==0) ? j : j+1] += dp[i][1][j]; // 未満
                    else{
                        if(c == c_) dp[i+1][0][(c==0) ? j : j+1] += dp[i][sm][j];
                        if(c == 0 && c < c_) dp[i+1][1][j] += dp[i][sm][j];
                        if(c != 0 && c < c_) dp[i+1][1][j+1] += dp[i][sm][j];
                    }
                }
            }
        }
    }

    // Rep(i, 1, n){
    //     rep(sm, 0, 2){
    //         rep(j, 0, k+1){
    //             printf("dp[%lld][%lld][%lld] = %lld, ", i, sm, j, dp[i][sm][j]);
    //         }
    //         coel;
    //     }
    //     coel;
    // }

    cout << dp[n][0][k] + dp[n][1][k] << endl;

    
    return 0;
}