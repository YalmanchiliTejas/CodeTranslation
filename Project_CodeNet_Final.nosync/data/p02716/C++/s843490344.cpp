#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(), (x).end())
#define RSORT(x) sort((x).rbegin(), (x).rend())
#define ALL(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define reps(i, m, n) for (ll i = m; i < n; i++)
#define repr(i, m, n) for (ll i = m; i >= n; i--)
#define de(x) cout << #x << "=" << x << endl;
#define SP << " " <<
template <class T> bool maxi(T &a, const T &b) {
    if (a < b) { a = b; return 1;} return 0;}
template <class T> bool mini(T &a, const T &b) {
    if (b < a) { a = b; return 1;} return 0;}
#define dame {cout<< "-1" <<"\n"; return;}
#define INF2 1000000000000000037
#define INF  1000000007
#define MOD  1000000007
using namespace std;
using ll = long long;
using ld = long double;
using vv = vector<vector<ll>>;
using P  = pair<ll,ll>;
//--GLOBAL---------------------------------

//--MAIN-----------------------------------
void Main() {
    ll N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vv dp(N+2,vector<ll>(3,-INF2));
    dp[0][0]=0;
    reps(i,2,N+2){
        rep(j,3){
            rep(k,3) {
                if(i-2-k<0 or j+k>2) continue;
                maxi(dp[i][j+k],dp[i-2-k][j]+A[i-2]);
            }
        }
    }
    cout<< ( N%2 ? max({dp[N+1][2],dp[N+1-1][1],dp[N+1-2][0]}) : max(dp[N+1][1],dp[N+1-1][0] )) <<"\n";
}

//--START----------------------------------
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------------
