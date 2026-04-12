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

ll win(int i, int j){
    return (S[abs(i - j) - 1] == '0' ? min(i, j) : max(i, j));
}

int main() {
    cin>>N>>S;
    ll sz = 1LL<<N;//Sのサイズー１
    mat dp(N + 1, vec(sz));
    rep(i,sz) {
        cin>>dp[0][i];
        --dp[0][i];
    }
    rep(n,N){
        //cout<<n<<endl;
        rep(i,sz){
            dp[n+1][i] = win(dp[n][i], dp[n][(i + (1<<n))%sz]);
            //cout<<i<<' '<<dp[n][i]<<' '<<dp[n][(i + (1<<n))%sz]<<' '<<dp[n+1][i]<<endl;
        }
    }
    rep(i,sz)cout<<dp[N][i] + 1<<endl;
}
