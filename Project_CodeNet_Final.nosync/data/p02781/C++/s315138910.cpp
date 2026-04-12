#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> VECLL;
typedef vector<P> VECP;
typedef priority_queue<P,VECP,greater<P> > PQP;
typedef priority_queue<ll, VECLL, greater<ll> > PQll;

#define rep(i,a,n) for(ll i = a;i < n;i++)   
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;


int main(){ 
    string s;
    ll k;
    cin >> s >> k;
    ll n = (ll)s.size();

    ll dp[101][2][101];
    rep(i,0,101) rep(j,0,2) rep(k,0,101) dp[i][j][k] = 0;

    dp[0][0][0] = 1;

    rep(i,0,n){
        rep(j,0,n){
            if(s[i] == '0'){
                dp[i+1][0][j] += dp[i][0][j];
            }
            else{
                dp[i+1][0][j+1] += dp[i][0][j];
                dp[i+1][1][j+1] += ((ll)(s[i] - '0') - 1)*dp[i][0][j];
                dp[i+1][1][j] += dp[i][0][j];
            }

            dp[i+1][1][j+1] += 9*dp[i][1][j];
            dp[i+1][1][j] += dp[i][1][j];
        }
    }

    cout << dp[n][0][k] + dp[n][1][k] << endl;
}
