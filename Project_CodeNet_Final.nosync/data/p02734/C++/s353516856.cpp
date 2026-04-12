#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S;
const ll MOD = 998244353;
//const ll MOD = (1e+9) + 7;
const ll INF = 1LL<<60;
typedef pair<ll, ll> P;

int main() {
    cin>>N>>K;
    mat dp(N + 1, vec(K + 1, 0));
    dp[0][0] = 1;
    vec a(N + 1);
    rep(i,N) cin>>a[i + 1];
    reps(i,1,N + 1){
        rep(j, K + 1){
            dp[i][j] = dp[i-1][j];
            if(j >= a[i]) (dp[i][j] += (j == a[i] ? i : 1LL) * dp[i-1][j - a[i]])%=MOD;
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    ll ans = 0;
    reps(i,1,N + 1) (ans += ((MOD + dp[i][K] - dp[i-1][K])%MOD) * (N + 1 - i))%=MOD;
    cout<<ans<<endl;
}