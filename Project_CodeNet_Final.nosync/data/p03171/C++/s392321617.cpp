#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
struct edge{ll to,cost;};
const int inf = 1<<27;
const ll INF = 1LL<<60;
const int COMBMAX = 1001001;
const ll MOD = 1000000007;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for(const auto& e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (ll)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (ll)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
ll mpow(ll a, ll n, ll mod = MOD){ll res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void YesNo(bool j){cout << (j ? "Yes" : "No") << endl; return;}
void yesno(bool j){cout << (j ? "yes" : "no") << endl; return;}
template<class T1, class T2> ll bcount(T1 v, T2 a){return upper_index(v, a) - lower_index(v, a);} 
template<class T> inline bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T> void debug(T v){rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}

ll N;
ll a[3030];
ll dp[3030][3030][2];

ll rec(ll l, ll r, ll t){
    // cout << l << " " << r <<" "<< t << endl;
    if (dp[l][r][t] != -1) return dp[l][r][t];
    if (l == r){
        dp[l][r][t] = a[l] * (1 - 2 * t);
    }else{
        if (!t) dp[l][r][t] = max(rec(l + 1, r, 1) + a[l], rec(l, r - 1, 1) + a[r]);
        else dp[l][r][t] = min(rec(l + 1, r, 0) - a[l], rec(l, r - 1, 0) - a[r]);
    }
    return dp[l][r][t];
}


int main(){
    cin >> N;
    rep(i, N) cin >> a[i];
    rep(i, N) rep(j, N) rep(k, 2) dp[i][j][k] = -1;
    cout << rec(0, N - 1, 0) << endl;
    return 0;
}